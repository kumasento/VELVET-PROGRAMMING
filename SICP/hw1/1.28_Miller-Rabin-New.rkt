#lang planet neil/sicp

(define (Miller-Rabin)
  (define (even? n) (= (remainder n 2) 0))
  (define (square x) (* x x))
  (define (get-t n cnt) 
    (if (even? n)
        (get-t (/ n 2) (+ cnt 1))
        cnt))
  (define (less-equal a b) 
    (and (< a b) (= a b)))
  (define (filter a mod cnt t)
    (cond ((= cnt 0) (if (= (remainder a mod) 1) a 0))
          ((less-equal cnt t) (not (= (remainder a mod) 1)) a 0)
          (else a)))
               
  (define (expmod-revise base exp mod cnt t)
    (cond ((= exp 0) 1)
          ((even? exp) (filter (square (expmod-revise base (/ exp 2) mod (+ cnt 1) t)) mod cnt t))
          (else (filter (* base (expmod-revise base (- exp 1) mod (+ cnt 1) t)) mod cnt t))))
  
  (display "Welcome!\nPlease Enter a Number:")
  (define n (read))
  (cond ((= n 1) (display "I cant tell"))
        ((= n 2) (display "Prime")) 
        ((= (expmod-revise (+ (random (- n 2)) 2) (- n 1) n 0 (get-t (- n 1) 0)) 0) (display "Not Prime"))
        (else (display "Prime"))))

(Miller-Rabin)
               
     
               