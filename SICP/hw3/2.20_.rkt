#lang planet neil/sicp

(define (same-parity x . items)
  (define (even? x)
    (if (= (remainder x 2) 0) 1 0))
  (define (same-parity-iter x items)
    (if (null? items)
        nil
        (if (= (even? (car items)) (even? x))
            (cons (car items) (same-parity-iter x (cdr items)))
            (same-parity-iter x (cdr items)))))
    (cons x (same-parity-iter x items)))

(display (same-parity 2 2 3 4 5 7))