#lang planet neil/sicp
(define (new-if pred then els)
  (cond (pred then)
        (else els)))
(define (square x) (* x x))
(define (ok g x) 
  (< (abs (- (square g) x)) 1e-6))
(define (imp g x)
  (/ (+ g (/ x g)) 2))
(define (sqrt-iter g x)
  (new-if (ok g x)
      g
      (sqrt-iter (imp g x) x)))
(sqrt-iter 1.0 3)
