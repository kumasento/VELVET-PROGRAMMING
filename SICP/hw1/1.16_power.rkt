#lang planet neil/sicp


(define (even? n)
  (= (remainder n 2) 0))

(define (fast-power-iter a b c counter)
  (cond ((= counter 1) (* b c))
        ((even? counter) (fast-power-iter a (* b b) c (/ counter 2)))
        (else (fast-power-iter a b (* c a) (- counter 1)))))

(define (fast-power b n)
  (fast-power-iter b b 1 n))
