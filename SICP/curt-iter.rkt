#lang planet neil/sicp

(define (ok old-g new-g)
  (< (abs (- old-g new-g)) 1e-6))
(define (cube x) (* x x x))
(define (imp g x)
  (/ (+ (/ x (* g g)) (* 2 g)) 3))
(define (curt-iter g x)
  (if (ok g (imp g x))
      g
      (curt-iter (imp g x) x)))
(curt-iter 1.0 3)

