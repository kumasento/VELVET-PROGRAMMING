#lang planet neil/sicp

(define (newton-method g guess)
  (define (fixed-point f first-guess)
    (define tolerance 0.00001)
    (define (close-enough? v1 v2)
      (< (abs (- v1 v2)) tolerance))
    (define (try guess)
      (let ((next (f guess)))
        (if (close-enough? guess next)
            next 
            (try next))))
    (try first-guess))
  (define (newton-transform g)
    (define (deriv g)
      (define dx 0.00001)
      (lambda (x)
        (/ (- (g (+ x dx)) (g x)) dx)))
    (lambda (x)
      (- x (/ (g x) ((deriv g) x)))))
  (fixed-point (newton-transform g) guess))

(define (sqrt x)
  (newton-method (lambda (y) (- (* y y) x))
                 1.0))

(define (cubic a b c)
  (lambda (x)
    (+ (* x x x) (* a x x) (* b x) c)))

(newton-method (cubic 3 3 1) 1)