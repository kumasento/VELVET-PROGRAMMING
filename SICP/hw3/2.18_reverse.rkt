#lang planet neil/sicp

(define (list-ref items n)
    (if (= n 1)
        (car items)
        (list-ref (cdr items) (- n 1))))
  (define (get-reverse n i)
    (- n i))
  (define (reverse-iter x n)
    (if (= n 1)
        (cons (list-ref x 1) nil)
        (cons (list-ref x n) (reverse-iter x (- n 1)))))
  (define (length x)
    (if (null? x)
        0
        (+ 1 (length (cdr x)))))
(define (reverse x)
  (reverse-iter x (length x)))

(display (reverse (list 1 2 3)))
