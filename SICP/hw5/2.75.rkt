#lang planet neil/sicp

(define (make-cos angle)
  (list 'cos angle))
(define (make-sin angle)
  (list 'sin angle))
(define (make-product a b)
  (list '* a b))

(define (make-from-mag-angle mag angle)
  (define (square x) (* x x))
  (define (dispatch op)
    (cond ((eq? op 'real-part) (make-product mag (make-cos angle)))
          ((eq? op 'imag-part) (make-product mag (make-sin angle)))
          ((eq? op 'magnitude) mag)
          ((eq? op 'angle) angle)
          (else
           (error "Unknown op -- MAKE FROM MAG ANGLE" op))))
  dispatch)

(display ((make-from-mag-angle 'z 'arg)  'real-part))
(display "\n")
(display ((make-from-mag-angle 'z 'arg)  'imag-part))
(display "\n")
(display ((make-from-mag-angle 'z 'arg)  'magnitude))
(display "\n")
(display ((make-from-mag-angle 'z 'arg)  'angle))
