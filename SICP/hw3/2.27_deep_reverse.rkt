#lang planet neil/sicp

(define (deep-reverse x)
  (define (length x)
    (if (null? x)
        0
        (+ 1 (length (cdr x)))))
  (define (list-ref items n)
    (if (= n 1)
        (car items)
        (list-ref (cdr items) (- n 1))))
  (define (get-reverse-id n i)
    (+ (- n i) 1))
  (define (deep-reverse-iter x n)
    (if (= n 1)
        (cons (deep-reverse (list-ref x 1)) nil)
        (cons (deep-reverse (list-ref x n)) (deep-reverse-iter x (- n 1)))))
  (if (not (pair? x))
      x
      (deep-reverse-iter x (length x))))

(display (deep-reverse (list (list 1 2) (list 3 (list 4 5)))))