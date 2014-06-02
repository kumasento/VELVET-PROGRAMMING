(load "mod.scm")
(load "teval.scm")

(define (error reason . args)
      (display "Error: ")
      (display reason)
      (for-each (lambda (arg) 
                  (display " ")
		  (write arg))
		args)
      (newline)
      (scheme-report-environment -1))  ;; we hope that this will signal an error

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

;;;;;;;;;;;;;;;;;;;;; Lab Exercise 7
;; pre-experiments
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

;;real procedures:
;;1. a predicate to make sure if the variable is in the env
(define (is-generic-function-in-env? var env)
  (let ((b (binding-in-env var env)))
    (if (found-binding? b)
        (let ((gf (tool-eval var env)))
          (generic-function? gf))
        #f)))

;;2. the new one
(define (eval-define-method exp env)
  (let ((gf-name (method-definition-generic-function exp)))
    (begin
      (if (is-generic-function-in-env? gf-name env)
          'found-generic-function
          (begin
            (tool-eval `(define-generic-function ,gf-name) env)
            (list 'new 'generic 'function gf-name)))      
      (let ((gf (tool-eval (method-definition-generic-function exp) env)))
        (if (not (generic-function? gf))
            (error "Unrecognized generic function -- DEFINE-METHOD >> "
                   (method-definition-generic-function exp))
            
            (let ((params (method-definition-parameters exp)))
              (install-method-in-generic-function
               gf
               (map (lambda (p) (paramlist-element-class p env))
                    params)
               (make-procedure (make-lambda-expression
                                (map paramlist-element-name params)
                                (method-definition-body exp))
                               env))
              (list 'added 'method 'to 'generic 'function:
                       (generic-function-name gf))))))))

;; Lab 8
(define (eval-define-class exp env)
  (let ((superclass (tool-eval (class-definition-superclass exp)
                               env)))
    (if (not (class? superclass))
        (error "Unrecognized superclass -- MAKE-CLASS >> "
               (class-definition-superclass exp))
        (let ((name (class-definition-name exp))
              (all-slots (collect-slots
                          (class-definition-slot-names exp)
                          superclass)))
          (let ((new-class
                 (make-class name superclass all-slots)))
            (define-variable! name new-class env)
            (list 'defined 'class: name)
            (for-each
             (lambda (entry) 
               (begin
                 (if (is-generic-function-in-env? entry env)
                     (list `generic `function entry `exist)
                     (begin
                       (tool-eval 
                        `(define-generic-function ,entry)
                        env)
                       ))
                 (tool-eval
                  `(define-method ,entry ((x ,name)) (get-slot x ',entry))
                  env)
                 ))
             all-slots)
            )))))

;;(define entry 1)
;;`(define-generic-function ,entry)
(define entry 'size)
(define name '<cat>)
`(define-method ,entry ((x ,name)) (get-slot x ',entry))
(initialize-tool)
