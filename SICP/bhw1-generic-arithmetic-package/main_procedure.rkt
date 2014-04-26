;;; put-get -- functions to manage the table
(load "put-get.scm")
;;;types -- apply-generic and type tagging
(load "types.scm")

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(load "ps5-code-revised.scm")

;Lab Exercise 5.1B
(define num1 (create-number 1))
(define num2 (create-number 2))
(define num4 (create-number 4))
(define num1-copy (create-number 1))

(define (add x y) (apply-generic 'add x y))
(define (sub x y) (apply-generic 'sub x y))
(define (mul x y) (apply-generic 'mul x y))
(define (div x y) (apply-generic 'div x y))
(define (negate x) (apply-generic 'negate x))
(define (=zero? x) (apply-generic '=zero? x))
(define (equ? x y) (apply-generic 'equ? x y))

(equ? num1 num2) ;; should be false
(equ? num1 num1-copy) ;; should be true

;Exercise 5.3B
(define rat1 (create-rational num1 num2))
(define rat2 (create-rational num2 num4))
(define rat3 (create-rational num1 num2))

(equ? rat1 rat2) ;;should be false, because there's no fraction reduction
(equ? rat1 rat3) ;;should be true

;Exercise 5.4A
;method definitions:

;Test repnum->reprat
(define nrat1 (repnum->reprat 2))
nrat1
;Test operation
(add num2 rat1)
(sub num2 rat1)
(mul num2 rat1)
(div num2 rat1)

(define rat21 (create-rational num2 num1))
(equ? num2 rat21)

;Exercise 5.4B
(define n2 (create-number 2))
(define r5/13 (create-rational (create-number 5) (create-number 13)))
(equ? (sub (add n2 r5/13) r5/13) n2)
