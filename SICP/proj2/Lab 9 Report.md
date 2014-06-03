#Proj2 Lab 9 Report 

##测试思路：
1. 为了直接在TOOL的交互式环境中进行测试，需要在`tool-eval`和`tool-apply`中添加接口：
    * 由于任何一个在TOOL的交互式环境中输入的表达式，首先被传递到`tool-eval`中，因此只需要在`tool-eval`中添加一个入口即可(以谓词判断函数为例):
    
        ~~~
        ((generic-function-predicate-checker? exp) 
            (eval-gfpredicate-checker exp env))
        ;; The one will check the predicate
        ~~~
    * 对应的入口条件判断函数：
   
        ~~~
        (define (generic-function-predicate-checker? exp)
          (tagged-list? exp 'gf-checker))
        ~~~
    * 执行函数：
        1. 首先判断`tool-eval`是否成功解析：
        
            ~~~
            (define (eval-gfpredicate-checker exp env)
              'hello-world)
            ;; success if hello-world shows up
            ~~~  
            执行结果(Img1)：
            ![image](http://)
        2. 之后添加判断过程即可
2. 测试`generic-function`是否正确生成， 主要有以下3步:
    1. `generic-function`的判定谓词是否正确，方法：
    
        ~~~
        (gf-checker gf-name)
        ;; gf-name is the quoted name of the generic function you need to check
        ~~~
        具体代码：
        
        ~~~
        (define (eval-gfpredicate-checker exp env)
          (let ((gf-name (gf-checker-gfname exp)))
            (is-generic-function-in-env? gf-name env)))
        ;; if the gf has not been defined, it will return #f
        ;; otherwise, it will return #t
        ~~~
        测试结果(Img2)：  
        ![image](http://)  
        
    2. 添加后的`generic-function`是否可以正确使用：
        测试结果(Img3)：
        ![image](http://)  
    
3. 测试`define-class`是否正确生成`slot-name`对应的`method`:
    1. 测试的几个要点：
        * `generic-function`生成
        * `method`生成
        * `method`对应的参数类型正确，即子类的`slot`生成的过程不能被`superclass`使用
        * `method`的输出正确
    2. 测试结果(Img4)：
        ![image](http://)
        