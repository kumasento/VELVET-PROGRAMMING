#lang planet neil/sicp

(define (get-N n) (/ (+ -1 (sqrt (+ (* 8 n) 1))) 2))
(define (get-layer n)  
  (define x (get-N n))
  (if (= x (floor x))
      x
      (+ (floor x) 1)))
  (define (get-upper-left n)
    (- n (get-layer n)))
  (define (get-upper-right n)
    (+ (get-upper-left n) 1))
  (define (is-boundary n)
    (define x (get-layer n))
    (or (= n (/ (* x (+ x 1)) 2))
        (= n (- (/ (* x (+ x 1)) 2) (- x 1)))))
(define (getpas n)
  (if (is-boundary n) 
      1
      (+ (getpas (get-upper-right n)) (getpas (get-upper-left n)))))

(getpas 8)




