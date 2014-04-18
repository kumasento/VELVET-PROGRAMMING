#lang planet neil/sicp

(define (fib3 n)
  (define (fib3-iter a b c count)
    (if (= count 0)
        a
        (fib3-iter (+ (+ a (* b 2)) (* c 3)) a b (- count 1))))
  (if (< n 4) n
      (fib3-iter 3 2 1 (- n 3))))
(define (checker)
  (display "Enter a number:\n")
  (define n (read))
  (display "Answer is ") 
  (fib3 n))
(checker)
