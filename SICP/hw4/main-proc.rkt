#lang planet neil/sicp

;declarence
;number?
(define (=number? a b)
  (and (number? a) (= a b)))
;check exp length
(define (length x)
  (if (null? x)
      0
      (+ 1 (length (cdr x)))))
(define (exp-arbitrary exp) (= (length exp) 3))
(define (build-newexp operator operands-list)
  (cons operator (cdr (cdr operands-list))))

;is symbol?
(define (variable? x) (symbol? x))
;same symbols?
(define (same-variable? v1 v2)
  (and (variable? v1) (variable? v2) (eq? v1 v2)))
;make list
(define (make-sum a1 a2) 
  (cond ((=number? a1 0) a2)
        ((=number? a2 0) a1)
        ((and (number? a1) (number? a2)) (+ a1 a2))
        ((eq? a1 a2) (make-product 2 a1))
        (else (list '+ a1 a2))))
;(define (make-sum a1 a2) (list '+ a1 a2))

(define (make-product m1 m2)
  (cond ((or (=number? m1 0) (=number? m2 0)) 0)
        ((=number? m1 1) m2)
        ((=number? m2 1) m1)
        ((and (number? m1) (number? m2) (* m1 m2)))
        (else (list '* m1 m2))))
;is sum?
(define (sum? x)
  (and (pair? x) (eq? (car x) '+)))
;elements in sum
(define (augend s) 
  (if (exp-arbitrary s) 
      (caddr s)
      (build-newexp '+ s)))
(define (addend s) (cadr s))

;multiply
(define (product? x)
  (and (pair? x) (eq? (car x) '*)))
(define (multiplier p) (cadr p))
(define (multiplicand p) 
  (if (exp-arbitrary p) 
      (caddr p)
      (build-newexp '* p)))

;infix 
(define (get-infix exp) 
  (cadr exp))
(define (is-infix exp)
  (or (eq? (get-infix exp) '+) (eq? (get-infix exp) '*)))
(define (get-operand1 exp)
  (car exp))
(define (get-operand2 exp)
  (if (> (length exp) 3)
      (cdr (cdr exp))
      (caddr exp)))
(define (sum-converter exp)
  (make-sum (get-operand1 exp) (get-operand2 exp)))
(define (multi-converter exp)
  (if (= (length exp) 3)
      (make-product (get-operand1 exp) (get-operand2 exp))
      (list (get-infix (get-operand2 exp)) 
            (make-product (get-operand1 exp) (caddr exp))
            (get-operand2 (get-operand2 exp)))))
                  

;My implementation
;power
(define (fast-power b n)
  (define (even? n)
  (= (remainder n 2) 0))
  (define (fast-power-iter a b c counter)
    (cond ((= counter 1) (* b c))
          ((even? counter) (fast-power-iter a (* b b) c (/ counter 2)))
          (else (fast-power-iter a b (* c a) (- counter 1)))))
  (fast-power-iter b b 1 n))
(define (exponentiation? x)
  (and (pair? x) (eq? (car x) '**)))
(define (base x) (cadr x))
(define (exponent x) (caddr x))
(define (make-exponentiation b e)
  (cond ((=number? e 0) 1)
        ((=number? b 1) 1)
        ((=number? b 0) 0)
        ((and (number? b) (number? e)) (fast-power b e))
        (else (list '** b e))))

;sin and cos
(define (sin? exp)
  (eq? (car exp) 'sin))
(define (cos? exp)
  (eq? (car exp) 'cos))

      
;main process
;added arbitrary number of operands situation procedure
(define (deriv exp var)
  (cond ((number? exp) 0)
        ((variable? exp)
         (if (same-variable? exp var) 1 0))
        
       ((sum? exp)
               (make-sum (deriv (addend exp) var)
                         (deriv (augend exp) var)))
       ((product? exp)
        (make-sum
         (make-product (multiplier exp)
                       (deriv (multiplicand exp) var))
         (make-product (deriv (multiplier exp) var)
                       (multiplicand exp))))
       ((exponentiation? exp)
        (make-product (make-product (exponent exp) 
                                    (make-exponentiation (base exp)
                                                         (make-sum (exponent exp) -1)))
                      (deriv (base exp) var)))
       ((sin? exp) 
        (make-product (deriv (cadr exp) var)
                      (cons 'cos (cadr exp))))
       ((cos? exp)
        (list '-
        (make-product (deriv (cadr exp) var)
                      (cons 'sin (cadr exp)))))
       ((eq? (cadr exp) '+)
        (deriv (sum-converter exp) var))
       ((eq? (cadr exp) '*)
        (deriv (multi-converter exp) var))
       (else
        (error "unkown expression type -- DERIV" exp))))

(display "Here is the examples from the book\n")
(display (deriv '(+ x 3) 'x))
(display "\n")
(display (deriv '(* x y) 'x))
(display "\n")
(display (deriv '(* (* x y) (+ x 3)) 'x))
(display "\n")

(display "Here is my examples:\n")
(display "exponentiations:\n")
(display (deriv '(** x y) 'x))
(display "\n")
(display (deriv '(** x -2) 'x))
(display "\n")
(display "arbitrary number of operands:\n")
(display (deriv '(+ x x x) 'x))
(display "\n")
(display (deriv '(* x y (+ x 3)) 'x))
(display "\n")

(display "infix:\n")
(display (deriv '(x + (3 * (x + (y + 2)))) 'x))
(display "\n")

(display "multiple infix:\n")
(display (deriv '(x + 3 * ( x + y + z)) 'x))
(display "\n")
(display (deriv '(x * x + x) 'x))
(display "\n")

(display "sin and cos:\n")
;(display (cdr '(sin (+ x 2))))
(display (deriv '(sin (* x 2)) 'x))
(display "\n")
(display (deriv '(cos (* x 2)) 'x))