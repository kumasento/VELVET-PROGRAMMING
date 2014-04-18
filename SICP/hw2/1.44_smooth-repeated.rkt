#lang planet neil/sicp

(define (smooth-repeated f n)
  (define (repeated f n)
    (if (= n 0)
        f
        (repeated (lambda (x) (f (f x))) (- n 1))))
  (define dx 0.00001)
  (define (smooth f)
    (lambda (x) (/ (+ (f x) (f (+ x dx)) (f (- x dx))) 3)))
  (repeated (smooth f) n))

((smooth-repeated (lambda (x) (* x x)) 1) 1)