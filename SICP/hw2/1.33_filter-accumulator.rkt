#lang planet neil/sicp

(define (filter-accumulator filter combiner null-value term a next b)
  (cond ((> a b) null-value)
        ((filter a) (combiner (term a) (filter-accumulator filter combiner null-value term (next a) next b)))
        (else (filter-accumulator filter combiner null-value term (next a) next b))))

(define (naive-prime n)
  (define (less-equal a b) (or (< a b) (= a b)))
  (define (naive-prime-iter n cnt)
    (if (less-equal cnt (sqrt n))
        (if (= (remainder n cnt) 0)
            #f
            (naive-prime-iter n (+ cnt 1)))
        #t))
  (cond ((= n 1) #f)
        ((= n 2) #t)
        (else (naive-prime-iter n 2))))

(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (remainder a b))))

(display "Enter the mode:[1] Prime?; [2] GCD?\n")
(define mode (read))
(cond ((= mode 1)
       (display "Enter a and b:\n")       
       (filter-accumulator naive-prime + 0 (lambda (x) x) (read) (lambda (x) (+ x 1)) (read)))
      ((= mode 2) 
       (display "n is 10\n")
       (filter-accumulator (lambda (x) (= (gcd x 10) 1)) * 1 (lambda (x) x) 1 (lambda (x) (+ x 1)) 10)))