;;; put-get -- functions to manage the table
(load "put-get.scm")
;;;types -- apply-generic and type tagging
(load "types.scm")

(load "ps5-code-revised.scm")

;Lab Exercise 5.1B
(define num1 (create-number 1))
(define num2 (create-number 2))
(define num1-copy (create-number 1))

(define (equ? x y) (apply-generic 'equ? x y))

(equ? num1 num2) ;; should be false
(equ? num1 num1-copy) ;; should be true