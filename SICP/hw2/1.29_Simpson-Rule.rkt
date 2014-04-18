#lang planet neil/sicp

(define (simpson f a b n)
  (define h (/ (- b a) n))
  (define (f-cal k)
    (f (+ a (* k h))))
  (define (even? n) (= (remainder n 2) 0))
  (define (simpson-iter f a b n cnt sum)
    (cond ((= cnt (+ n 1)) (* (/ h 3) sum))
          ((or (= cnt 0) (= cnt n)) (simpson-iter f a b n (+ cnt 1) (+ sum (f-cal cnt))))
          ((even? cnt) (simpson-iter f a b n (+ cnt 1) (+ sum (* 4 (f-cal cnt)))))
          (else (simpson-iter f a b n (+ cnt 1) (+ sum (* 2 (f-cal cnt)))))))
  (simpson-iter f a b n 0 0))

(define (integral f a b dx)
  (define (add-dx x) (+ x dx))
  (define (sum term a next b)
    (if (> a b)
        0
        (+ (term a)
           (sum term (next a) next b))))
  (* (sum f (+ a (/ dx 2.0)) add-dx b)
     dx))

(define (cube x) (* x x x))

(display "define the dx and divide-pieces in the following procedures:\n")
(display "dx:")
(define dx (read))
(display "n:")
(define n (read))
(display "integral:\n")
(define int-a (integral cube 0 1 dx))
int-a
(display "simpson:\n")
(define simp-a (simpson cube 0 1 n))
simp-a
(display "integral/simpson:") 
(/ (abs (- int-a 1/4)) (abs (- simp-a 1/4)))
                      