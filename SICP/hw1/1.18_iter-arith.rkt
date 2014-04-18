#lang planet neil/sicp

(define (fast-multi a b)
  (define (double n) (* n 2))
  (define (halve n) (/ n 2))
  (define (fast-multi-iter a b c)
    (define (even? n)
      (= (remainder n 2) 0))
    (cond ((= b 1) (+ a c))
          ((even? b) (fast-multi-iter (double a) (halve b) c))
          (else (fast-multi-iter a (- b 1) (+ c a)))))
  (fast-multi-iter a b 0))


          
   