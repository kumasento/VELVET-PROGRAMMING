(load "mod.scm")
(load "teval.scm")

;;; Test Functions:
(sort `(1 2 3 4) <)
;(initialize-tool)

;; test the exp format
(define test-exp '(define (<var> <param>) <body>))
(car test-exp) ;; should be 'define
(cdr test-exp) ;; should be '((<var> <param>) <body>)
(cadr test-exp) ;; should be '(<var> <param>)
(cddr test-exp) ;; should be '<body>
(caadr test-exp) ;; should be '<var>
(cdadr test-exp) ;; should be '(<param>)
(cadadr test-exp) ;; should be '<param>
(cddadr test-exp) ;; should be '()

;; What is symbol?
(define a 'a)
(symbol? a) ;; symbol? returns true unless the var is quoted 

;; experiments to lab exercise 7
;; 1. Add method
(define t-initial-env (make-initial-environment))
;;gf
(for-each 
 (lambda (entry) (display (tool-eval (car entry) t-initial-env)) (display "\n"))
 initial-procedures)
;;param-list
(for-each 
 (lambda (entry) (display (cadr entry)) (display "\n"))
 initial-procedures)
;;class-info
(lookup-variable-value '<number> t-initial-env)
