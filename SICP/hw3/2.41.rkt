#lang planet neil/sicp

(define (fixsum-list n s)
  (define (accumulator op initial sequence)
    (cond ((null? sequence) initial)
          ((not (pair? (car (car sequence)))) sequence)
          (else (op (accumulator op initial (car sequence))
                    (accumulator op initial (cdr sequence))))))
  (define (map proc items)
    (if (null? items)
        nil
        (cons (proc (car items))
              (map proc (cdr items)))))
  (define (enumerate low high)
    (if (> low high)
        nil
        (cons low (enumerate (+ low 1) high))))
  (define (append list1 list2)
    (if (null? list1)
        list2
        (cons (car list1) (append (cdr list1) list2))))
  (define (get-pairflow n)
    (accumulator append nil 
                 (map (lambda (i)
                        (map (lambda (j) 
                               (map (lambda (k) (list i j k))
                                    (enumerate 1 n)))
                             (enumerate 1 n)))
                      (enumerate 1 n))))
  (define (filter predicate sequence)
    (cond ((null? sequence) nil)
          ((predicate (car sequence)) (cons (car sequence) (filter predicate (cdr sequence))))
          (else (filter predicate (cdr sequence)))))
  (define (get-x x)
    (car x))
  (define (get-y x)
    (car (cdr x)))
  (define (get-z x)
    (car (cdr (cdr x))))
  (define (sum-equal x)
    (and (and (not (= (get-x x) (get-y x))) (not (= (get-x x) (get-z x))) (not (= (get-z x) (get-y x))))
         (= (+ (car x) (car (cdr x)) (car (cdr (cdr x)))) s)))
  (filter sum-equal (get-pairflow n)))
(display (fixsum-list 10 6))
   
        
   
                  
