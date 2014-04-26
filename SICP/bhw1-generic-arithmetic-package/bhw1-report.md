#Generic Arithmetic Package
===
##Summary and Exercise Answer
* ###Ordinary Numbers
    * Summary: Too simple
    * Exercise:
        * 5.1A - simple wrap operation
* ###Rational Numbers
    * Summary:
        * **constructor**: make-rat
        * **selector**: numer & denom
        * **basic procedures**: do the operations separately on the numer part and denom part
    * Exercises:
        * **5.2**: [[961] [169]]
        * **5.3A**: equ-rat? -- type is (RepRat X RepRat) -> Bool
* ###Operations across different types
    * Summary:
        * **Simple coerce:**  
        Change number n to rational number n/1
    * Exercise:
        * **5.4A**:  
        Core procedure is --   
        
                (define (repnum->reprat num)
                  (make-rat (create-number num) (create-number 1)))
        **Explanations:**
        1. This procedure is in the ps5-code.scm file, included in the 
            
                (define (RRmethod->NRmethod method)
                  (lambda (num rat)
                    (method
                     (repnum->reprat num)
                     rat)))
           procedure, and the *RRmethod->NRmethod* procedure will be called in when you use *apply-generic*, and this procedure will tear down the tag of the number.  
           In the end, the *num* in *repnum->reprat* procudure should be pure number, without tag. And this is the most tricky part in this exercise.
        2. So you need to know the type of the parameter when you are defining the procedure, especially the one will be used in the *apply-generic*.
       * **5.4B**: In the code  
         **Tips**:  
         create-rational's parameter should be added tag:  
         
             (define r5/13 (create-rational (create-number 5) (create-number 13)))

         
         
       
       
        
            
        