#lang planet neil/sicp

;;; Generic Arithmetic

;;; Code for creating the table, you don't need to worry about this.

(define (make-table)
  (let ((local-table (list '*table*)))

    (define (lookup key-1 key-2)
      (let ((subtable (assoc key-1 (cdr local-table))))
        (if subtable
            (let ((record (assoc key-2 (cdr subtable))))
              (if record
                  (cdr record)
                  false))
            false)))

    (define (insert! key-1 key-2 value)
      (let ((subtable (assoc key-1 (cdr local-table))))
        (if subtable
            (let ((record (assoc key-2 (cdr subtable))))
              (if record
                  (set-cdr! record value)
                  (set-cdr! subtable
                            (cons (cons key-2 value)
                                  (cdr subtable)))))
            (set-cdr! local-table
                      (cons (list key-1
                                  (cons key-2 value))
                            (cdr local-table)))))
      'ok)

    (define (dispatch m)
      (cond ((eq? m 'lookup-proc) lookup)
            ((eq? m 'insert-proc!) insert!)
            (else (error "Unknown operation -- TABLE" m))))

    dispatch))


(define operation-table (make-table))
(define get (operation-table 'lookup-proc))
(define put (operation-table 'insert-proc!))




;;; The bottom level typing system


;;; This part has been revised -- 2.78
(define (attach-tag type-tag contents)
  (if (number? contents)
      contents
      (cons type-tag contents)))

(define (type-tag datum)
  (if (pair? datum)
      (car datum)
      (if (number? datum)
          'scheme-number
          (error "Bad typed datum -- TYPE-TAG" datum))))

(define (contents datum)
  (if (pair? datum)
      (cdr datum)
      (if (number? datum)
          datum
          (error "Bad typed datum -- CONTENTS" datum))))


;;; The apply-generic mechanism.  
;;;  Note that we don't deal with coercion here.

(define (apply-generic op . args)
  (let ((type-tags (map type-tag args)))
    (let ((proc (get op type-tags)))
      (if proc
          (apply proc (map contents args))
          (error "No method for the given types -- APPLY-GENERIC"
                 (list op type-tags))))))


;;; Some generic arithmetic procedures

(define (add x y) (apply-generic 'add x y))
(define (sub x y) (apply-generic 'sub x y))
(define (mul x y) (apply-generic 'mul x y))
(define (div x y) (apply-generic 'div x y))
(define (=zero? x) (apply-generic '=zero? x))
(define (minus x) (apply-generic 'minus x))

;;; The rational number package

(define (install-rational-package)
  ;; internal procedures
  (define numer car)
  (define denom cdr)
  (define (make-rat n d)
    (let ((g (gcd n d)))
      (if (= g 0)
          (cons 0 0)
          (cons (/ n g) (/ d g)))))
  (define (add-rat x y)
    (make-rat (+ (* (numer x) (denom y))
                 (* (numer y) (denom x)))
              (* (denom x) (denom y))))
  (define (sub-rat x y)
    (make-rat (- (* (numer x) (denom y))
                 (* (numer y) (denom x)))
              (* (denom x) (denom y))))
  (define (mul-rat x y)
    (make-rat (* (numer x) (numer y))
              (* (denom x) (denom y))))
  (define (div-rat x y)
    (make-rat (* (numer x) (denom y))
              (* (denom x) (numer y))))
  (define (minus-rat x)
    (make-rat (- 0 (numer x))
              (- 0 (denom x))))
  ;; interfaces
  (define (tag x) (attach-tag 'rational x))
  (put 'add '(rational rational)
       (lambda (x y) (tag (add-rat x y))))
  (put 'sub '(rational rational)
       (lambda (x y) (tag (sub-rat x y))))
  (put 'mul '(rational rational)
       (lambda (x y) (tag (mul-rat x y))))
  (put 'div '(rational rational)
       (lambda (x y) (tag (div-rat x y))))
  (put 'minus '(rational)
       (lambda (x) (tag (minus-rat x))))
  (put '=zero? '(rational) 
       (lambda (x) (= (contents x) 0)))
  
  (put 'make 'rational
       (lambda (n d) (tag (make-rat n d))))
  'done)

(define (make-rational n d)
  ((get 'make 'rational) n d))


;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Your code goes here ;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;; Install Scheme Number Package
(define (install-scheme-number-package)
  (define (tag x)
    (attach-tag 'scheme-number x))
  (put 'add '(scheme-number scheme-number)
       (lambda (x y) (tag (+ x y))))
  (put 'sub '(scheme-number scheme-number)
       (lambda (x y) (tag (- x y))))
  (put 'mul '(scheme-number scheme-number)
       (lambda (x y) (tag (* x y))))
  (put 'div '(scheme-number scheme-number)
       (lambda (x y) (tag (/ x y))))
  (put 'make 'scheme-number
       (lambda (x) (tag x)))
  
  (put '=zero? '(scheme-number)
       (lambda (x) (= (contents x) 0)))
  (put 'minus '(scheme-number)
       (lambda (x) (- 0 (contents x))))
  'done)

;;; Install Rectangular Package
(define (install-rectangular-package)
  (define (real-part z) (car z))
  (define (imag-part z) (cdr z))
  (define (make-from-real-imag x y) (cons x y))
  (define (magnitute z)
    (sqrt (+ (* (real-part z) (real-part z))
             (* (real-part z) (real-part z)))))
  (define (angle z)
    (atan (imag-part z) (real-part z)))
  (define (make-from-mag-ang r a)
    (cons (* r (cos a)) (* r (sin a))))
  
  (define (tag x) (attach-tag 'rectangular x))
  (put 'real-part '(rectangular) real-part)
  (put 'imag-part '(rectangular) imag-part)
  (put 'magnitude '(rectangular) magnitude)
  (put 'angle '(rectangular) angle)
  (put 'make-from-real-imag 'rectangular
       (lambda (x y) (tag (make-from-real-imag x y))))
  (put 'make-from-mag-ang 'rectangular 
       (lambda (r a) (tag (make-from-mag-ang r a))))
  'done)

;;; Install Complex Number
(define (install-complex-package)
  (define (make-from-real-imag x y) 
    ((get 'make-from-real-imag 'rectangular) x y))
  (define (make-from-mag-ang r a)
    ((get 'make-from-real-imag 'polar) r a))
  (define (real-part z)
    ((get 'real-part 'rectangular) z))
  (define (imag-part z)
    ((get 'imag-part 'rectangular) z))
  (define (magnitude z)
    ((get 'magnitude 'rectangular) z))
  (define (angle z)
    ((get 'angle 'rectangular) z))
  
  (define (add-complex z1 z2)
    (make-from-real-imag (+ (real-part z1) (real-part z2))
                         (+ (imag-part z1) (imag-part z2))))
  (define (sub-complex z1 z2)
    (make-from-real-imag (- (real-part z1) (real-part z2))
                         (- (imag-part z1) (imag-part z2))))
  (define (mul-complex z1 z2)
    (make-from-mag-ang (* (magnitude z1) (magnitude z2))
                       (+ (angle z1) (angle z2))))
  (define (div-complex z1 z2)
    (make-from-mag-ang (/ (magnitude z1) (magnitude z2))
                       (- (angle z1) (angle z2))))
  (define (minus-complex z)
    (make-from-real-imag (- 0 (real-part z))
                          (- 0 (imag-part z))))
  (define (=zero? z)
    (and (= (real-part z) 0) (= (imag-part z) 0)))
  
  (define (tag z) (attach-tag 'complex z))
  (put 'add '(complex complex)
       (lambda (z1 z2) (tag (add-complex z1 z2))))
  (put 'sub '(complex complex)
       (lambda (z1 z2) (tag (sub-complex z1 z2))))
  (put 'mul '(complex complex)
       (lambda (z1 z2) (tag (mul-complex z1 z2))))
  (put 'div '(complex complex)
       (lambda (z1 z2) (tag (div-complex z1 z2))))
  (put '=zero? '(complex)
       (lambda (z) (=zero? z)))
  (put 'minus '(complex)
       (lambda (z) (minus-complex z)))
  (put 'make-from-real-imag 'complex 
       (lambda (x y) (tag (make-from-real-imag x y))))
  (put 'make-from-mag-ang 'complex
       (lambda (r a) (tag (make-from-mag-ang r a))))
 
  'done) 

;;; Term List

(define (make-term order coeff) (list order coeff))
(define (order term) (car term))
(define (coeff term) (cdr term))

(define (adjoint-term term term-list)
  (if (=zero? (coeff term))
      term-list
      (cons term term-list)))
(define (the-empty-termlist) '())
(define (first-term term-list) (car term-list))
(define (rest-terms term-list) (cdr term-list))
(define (empty-termlist? term-list) (null? term-list))

(define (minus-terms L)
  (if (empty-termlist? L)
      L
      (adjoint-term
       (make-term (order (first-term L))
                  (minus (coeff (first-term L))))
       (rest-terms L))))

(define (add-terms L1 L2)
  (cond ((empty-termlist? L1) L2)
        ((empty-termlist? L2) L1)
        (else
         (let ((t1 (first-term L1))
               (t2 (first-term L2)))
           (cond ((> (order t1) (order t2))
                  (adjoint-term 
                   t1 (add-terms (rest-terms L1) L2)))
                 ((< (order t1) (order t2))
                  (adjoint-term
                   t2 (add-terms L1 (rest-terms L2))))
                 (else 
                  (adjoint-term
                   (make-term (order t1)
                              (add (coeff t1) (coeff t2)))
                   (add-terms (rest-terms L1)
                              (rest-terms L2)))))))))

(define (mul-term-by-all-terms t1 L)
  (if (empty-termlist? L)
      (the-empty-termlist)
      (let ((t2 (first-term L)))
        (adjoint-term
         (make-term (+ (order t1) (order t2))
                    (mul (coeff t1) (coeff t2)))
         (mul-term-by-all-terms t1 (rest-terms L))))))
(define (mul-terms L1 L2)
  (if (empty-termlist? L1)
      (the-empty-termlist)
      (add-terms (mul-term-by-all-terms (first-term L1) L2)
                 (mul-terms (rest-terms L1) L2))))

;;; Polynomial
(define (install-polynomial-package)
  (define (make-poly variable term-list)
    (cons variable term-list))
  (define (variable p) (car p))
  (define (term-list p) (cdr p))
  (define (variable? x) (symbol? x))
  (define (same-variable? v1 v2)
    (and (variable? v1) (variable? v2) (eq? v1 v2)))
  
  (define (add-poly p1 p2)
    (if (same-variable? (variable? p1) (variable? p2))
        (make-poly (variable p1)
                   (add-terms (term-list p1)
                              (term-list p2)))
        (error "Polys not in the same var -- ADD-POLY"
               (list p1 p2))))
  (define (mul-poly p1 p2)
    (if (same-variable? (variable? p1) (variable? p2))
        (make-poly (variable p1)
                   (mul-terms (term-list p1)
                              (term-list p2)))
        (error "Polys not in the same var -- MUL-POLY"
               (list p1 p2))))
  (define (sub-poly p1 p2)
    (add-poly p1 
              (make-poly (variable p2)
                         (minus-terms (term-list p2)))))
  (define (=zero? p)
    (let ((L (term-list p)))
      (if (null? L)
          #t
          (and (= (first-term L) 0)
               (=zero? (rest-terms L))))))
  
  (define (tag p) (attach-tag 'polynomial p))
  (put 'add '(polynomial polynomial)
       (lambda (p1 p2) (tag (add-poly p1 p2))))
  (put 'mul '(polynomial polynomial)
       (lambda (p1 p2) (tag (mul-poly p1 p2))))
  (put 'make 'polynomial
       (lambda (var terms) (tag (make-poly var terms))))
  'done)
                         

;;; Some basic testing

(install-rational-package)
(install-scheme-number-package)
(install-rectangular-package)
(install-complex-package)
(install-polynomial-package)
