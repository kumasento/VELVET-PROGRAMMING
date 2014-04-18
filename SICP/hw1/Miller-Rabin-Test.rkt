#lang planet neil/sicp

(define (mr-test n)
  (define (even? n) (= (remainder n 2) 0))
  (define (square x) (* x x))
  (define (expmod base exp m)
    (cond ((= exp 0) 1)
          ((even? exp)
           (if (= (abs (remainder (square (expmod base (/ exp 2) m)) m)) 1)
                  (if (or (= exp (- n 1)) (= exp 1)) 1 0)
                  (square (expmod base (/ exp 2) m))))
          (else (* base (expmod base (- exp 1) m)))))
  (define (try-it a)
    (= (expmod a (- n 1) n) 1))
  (try-it (+ 1 (random (- n 1)))))

(mr-test 10037)
           