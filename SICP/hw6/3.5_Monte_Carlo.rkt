#lang planet neil/sicp

(define (random-real)
  (let ((rand-max 4294967087)) ; see document of Racket
    (/ (random rand-max)
       (exact->inexact rand-max))))

(define (random-in-range low high)
  (let ((range (- high low)))
    (+ low (* range (random-real)))))

(define (Pxy x1 x2 y1 y2)
      (lambda () 
        (let ((dx (- (random-in-range x1 x2) (/ (+ x1 x2) 2)))
              (dy (- (random-in-range y1 y2) (/ (+ y1 y2) 2))))
          (<= (+ (* dx dx) (* dy dy)) 1))))

(define (monte-carlo trails experiment)
  (define (iter trails-remaining trails-passed)
    (cond ((= trails-remaining 0) (/ trails-passed trails))
          ((experiment) (iter (- trails-remaining 1) (+ trails-passed 1)))
          (else (iter (- trails-remaining 1) trails-passed))))
  (iter trails 0))
(define (experiment-integral Pxy x1 x2 y1 y2 trails)
  (define square
    (* (abs (- x1 x2)) (abs (- y1 y2))))
  (* square (monte-carlo trails (Pxy x1 x2 y1 y2))))
                                
(display (experiment-integral Pxy 300 900 100 400 100000))
    