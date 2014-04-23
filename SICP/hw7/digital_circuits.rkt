#lang planet neil/sicp

;;; WIRE
; Main procedure
(define (make-wire)
  (let ((signal-value 0) (action-procedure '()))
    (define (set-my-signal! new-value)
      ;;; If you want to set a signal, 
      ;;; First you need to check if the new one is same as the old one
      ;;; If not, set the new signal and execute a action-procedure
      (if (not (= signal-value new-value))
          (begin (set! signal-value new-value)
                 (call-each action-procedure))
          'done)) ;;a little trick
      (define (accept-action-procedure! proc)
        (set! action-procedure (cons proc action-procedure))
        (proc)) ;;Execute the proc after setting is done
    (define (dispatch m)
      (cond ((eq? m 'get-signal) signal-value)
            ((eq? m 'set-signal!) set-my-signal!)
            ((eq? m 'add-action!) accept-action-procedure!)
            (else
             (error "Unkown operation -- WIRE" m))))
    dispatch))

; Added procedure
(define (call-each procedures)
  (if (null? procedures)
      'done
      (begin 
        ((car procedures))
        (call-each (cdr procedures)))))

;;; AGENDA
; QUEUE LIBRARY
(define (make-queue) (cons '() '()))
(define (front-ptr queue) (car queue))
(define (rear-ptr queue) (cdr queue))
(define (set-front-ptr! queue item) (set-car! queue item))
(define (set-rear-ptr! queue item) (set-cdr! queue item))
(define (empty-queue? queue)
  (null? (front-ptr queue)))

(define (front-queue queue)
  (if (empty-queue? queue)
      (error "Front-queue called with an empty queue")
      (car (front-ptr queue))))
(define (insert-queue! queue item)
  (let ((new-pair (cons item '())))
    (cond ((empty-queue? queue)
           (set-front-ptr! queue new-pair)
           (set-rear-ptr! queue new-pair)
           queue)
          (else
           (set-cdr! (rear-ptr queue) new-pair)
           (set-rear-ptr! queue new-pair)
           queue))))
(define (delete-queue! queue)
  (cond ((empty-queue? queue)
         (error "Delete-queue! called with an empty queue"))
        (else
         (set-front-ptr! queue (cdr (front-ptr queue)))
         queue)))

; Element 
(define (make-time-segment time queue) (cons time queue))
(define (segment-time s) (car s))
(define (segment-queue s) (cdr s))

; Basic functions:
(define (make-agenda) (list 0))
(define (current-time agenda) (car agenda))
(define (set-current-time! agenda time) (set-car! agenda time))
(define (segments agenda) (cdr agenda))
(define (set-segments! agenda segments) (set-cdr! agenda segments))
(define (first-segment agenda) (car (segments agenda)))
(define (rest-segments agenda) (cdr (segments agenda)))
(define (empty-agenda? agenda) (null? (segments agenda)))

; Main function:
(define (add-to-agenda! time action agenda) ;; 
  (define (belongs-before? segments)
    (or (null? segments) (< time (segment-time (car segments)))))
  (define (make-new-time-segment time action)
    (let ((q (make-queue)))
      (insert-queue! q action)
      (make-time-segment time q)))
  (define (add-to-segments! segments)
    (if (= (segment-time (car segments)) time)
        (insert-queue! (segment-queue (car segments)) action)
        (let ((rest (cdr segments)))
          (if (belongs-before? rest)
              (set-cdr! segments
                        (cons (make-new-time-segment time action) (cdr segments)))
              (add-to-segments! rest)))))
  (let ((segments (segments agenda)))
    (if (belongs-before? segments)
        (set-segments! agenda
                       (cons (make-new-time-segment time action) segments))
        (add-to-segments! segments))))
; Data Operation
(define (remove-first-agenda-item! agenda)
  (let ((q (segment-queue (first-segment agenda))))
    (delete-queue! q)
    (if (empty-queue? q)
        (set-segments! agenda (rest-segments agenda)))))
(define (first-agenda-item agenda)
  (if (empty-agenda? agenda)
      (error "Agenda is empty -- FIRST-AGENDA-ITEM" agenda)
      (let ((first-seg (first-segment agenda)))
        (set-current-time! agenda (segment-time first-seg))
        (front-queue (segment-queue first-seg)))))
;after-delay
(define (after-delay delay action)
  (add-to-agenda! (+ delay (current-time the-agenda))
                  action
                  the-agenda))
(define (propagate)
  (if (empty-agenda? the-agenda)
      'done
      (let ((first-item (first-agenda-item the-agenda)))
        (first-item)
        (remove-first-agenda-item! the-agenda)
        (propagate))))
; probe
(define (probe name wire)
  (add-action! wire
               (lambda ()
                 (newline)
                 (display name)
                 (display " ")
                 (display (current-time the-agenda))
                 (display " New-value= ")
                 (display (get-signal wire)))))
(define the-agenda (make-agenda))
(define inverter-delay 2)
(define and-gate-delay 3)
(define or-gate-delay 5)
       
;;; BUILD BASIC FUNCTIONAL BLOCK
; logic functions
(define (logic-not s)
  (cond ((= s 0) 1)
        ((= s 1) 0)
        (else
         (error "INVALID SIGNAL -- logic-not" ))))
(define (logic-and a b)
  (cond ((or (and (= a 0) (= b 0))
             (and (= a 1) (= b 0))
             (and (= a 0) (= b 1)))
         0)
        ((and (= a 1) (= b 1)) 1)
        (else 
         (error "INVALID SIGNAL -- logic-and" ))))
(define (logic-or a b)
  (cond ((or (and (= a 1) (= b 1))
             (and (= a 1) (= b 0))
             (and (= a 0) (= b 1)))
         1)
        ((and (= a 0) (= b 0)) 0)
        (else 
         (error "INVALID SIGNAL -- logic-or" ))))
; functional block
;(define (inverter input output)
(define (get-signal wire) (wire 'get-signal))
(define (set-signal! wire new-value) ((wire 'set-signal!) new-value))
(define (add-action! wire proc) ((wire 'add-action!) proc))

(define (inverter input output)
  (define (invert-input)
    (let ((new-value (logic-not (get-signal input))))
      (after-delay inverter-delay
                   (lambda()
                     (set-signal! output new-value)))))
    (add-action! input invert-input)
    'ok)
; test functions
;(define a (make-wire))
;(define b (make-wire))
;(inverter a b)
;(get-signal b)
;(set-signal! a 1)

; and gate
(define (and-gate a1 a2 output)
  (define (and-action-procedure)
    (let ((new-value
           (logic-and (get-signal a1) (get-signal a2))))
      (after-delay and-gate-delay 
                   (lambda ()
                     (set-signal! output new-value)))))
  (add-action! a1 and-action-procedure)
  (add-action! a2 and-action-procedure)
  'ok)
;(define c (make-wire))
;(and-gate a b c)
;(get-signal c)

; or gate
(define (or-gate a1 a2 output)
  (define (or-action-procedure)
    (let ((new-value
           (logic-or (get-signal a1) (get-signal a2))))
      (after-delay or-gate-delay
                   (lambda ()
                     (set-signal! output new-value)))))
  (add-action! a1 or-action-procedure)
  (add-action! a2 or-action-procedure)
  'ok)
  
(define input-1 (make-wire))
(define input-2 (make-wire))
(define sum (make-wire))
(define carry (make-wire))

(probe 'sum sum)
(probe 'carry carry)

; project1 -- half adder
(define (half-adder a b s c)
  (let ((d (make-wire)) (e (make-wire)))
    (or-gate a b d)
    (and-gate a b c)
    (inverter c e)
    (and-gate d e s)
    'ok))
(half-adder input-1 input-2 sum carry)
(set-signal! input-1 1)
(propagate)
(set-signal! input-2 1)
(propagate)

; project2 -- question 3.30
(define a1 (make-wire))
(define a2 (make-wire))
(define b1 (make-wire))
(define b2 (make-wire))
(define s1 (make-wire))
(define s2 (make-wire))
(define c-in (make-wire))
(define c-out (make-wire))

(define (full-adder a b c-in sum c-out)
  (let ((s (make-wire))
        (c1 (make-wire))
        (c2 (make-wire)))
    (half-adder a c-in s c1)
    (half-adder a s sum c2)
    (or-gate c1 c2 c-out)
    'ok))
        
(define (carry-adder a1 a2 b1 b2 s1 s2 c-in c-out)
  (let ((c (make-wire)))
    (full-adder a1 b1 c-in s1 c)
    (full-adder a2 b2 c s2 c-out)))

(display "carry-adder")
(probe 's1 s1)
(probe 's2 s2)
(probe 'carry c-out)
(carry-adder a1 a2 b1 b2 s1 s2 c-in c-out)
(set-signal! a1 1)
(propagate)
(set-signal! a2 1)
(propagate)