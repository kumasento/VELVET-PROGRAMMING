#lang planet neil/sicp

(define (new-if pred then els)
  (cond (pred then)
        (else els)))
(new-if #t (display "bad") (display "good"))
(if #t (display "bad") (display "good"))