#lang planet neil/sicp

;; Functions need to be implemented
; make-queue
; empty-queue?
; front-deque
; rear-deque
; front-insert-deque!
; rear-insert-deque!
; front-delete-deque!
; rear-delete-deque!

; make-queue example:
; (define (make-queue) (cons '() '())
(define (make-deque) (cons '() '()))

; opteration functions -- copied from the original queue implementation
(define (front-ptr queue) (car queue))
(define (end-ptr queue) (cdr queue))
(define (set-front-ptr! queue item) (set-car! queue item))
(define (set-end-ptr! queue item) (set-cdr! queue item))

; empty-deque?
; (define (empty-queue? queue) (null? (front-ptr queue)))
; To decide a queue is empty, the mark is its front-ptr
(define (empty-deque? deque) (null? (front-ptr deque)))

; access to elements
(define (front-deque deque)
  (if (empty-deque? deque)
      (error "FRONT called with an empty queue" deque)
      (car (front-ptr deque))))
(define (rear-deque deque)
  (if (empty-deque? deque)
      (error "END called with an empty queue" deque)
      (car (end-ptr deque))))

; A new data structure:
; (cons item (cons '() '())) 
; There are two pointers in one item pack
; "double linked list"
(define (prev-ptr tuple) (car (cdr tuple)))
(define (next-ptr tuple) (cdr (cdr tuple)))
(define (get-ptr tuple) (cdr tuple))
(define (get-item tuple) (car tuple))
(define (set-prev-ptr! t1 t2) (set-car! (get-ptr t1) t2))
(define (set-next-ptr! t1 t2) (set-cdr! (get-ptr t1) t2))

; change functions:
(define (front-insert-deque! deque item)
  (let ((new-pair (cons item (cons '() '()))))
    (cond ((empty-deque? deque)
           (set-front-ptr! deque new-pair)
           (set-end-ptr! deque new-pair)
           deque)
          (else
           (set-next-ptr! new-pair (front-ptr deque))
           (set-prev-ptr! (front-ptr deque) new-pair)
           (set-front-ptr! deque new-pair)
           deque))))
(define (rear-insert-deque! deque item)
  (let ((new-pair (cons item '())))
    (cond ((empty-deque? deque)
           (set-front-ptr! deque new-pair)
           (set-end-ptr! deque new-pair)
           deque)
          (else
           (set-prev-ptr! new-pair (end-ptr deque))
           (set-next-ptr! (end-ptr deque) new-pair)
           (set-end-ptr! deque new-pair)
           deque))))
(define (front-delete-deque! deque)
  (cond ((empty-deque? deque)
         (error "DELETE! called with an empty deque" deque))
        (else
         (set-front-ptr! deque (next-ptr (front-ptr deque)))
         deque)))
(define (rear-delete-deque! deque)
  (cond ((empty-deque? deque)
         (error "DELETE! called with an empty deque" deque))
        (else
         (set-end-ptr! deque (prev-ptr (end-ptr deque)))
         deque)))

(define DQ (make-deque))
(display (front-insert-deque! DQ 1))
(display "\n")
(display (front-delete-deque! DQ))
(display "\n")