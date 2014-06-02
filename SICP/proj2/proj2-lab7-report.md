#Proj2 Lab 7 Experiment
---

预备阅读:

1. 初始化环境的方式(env):  
    * 环境变量主要保存于`initial-objects`中，可以通过`map`与`car` `cdr`进行访问；  
    * 在`initial-objects`的基础之上，通过`extend-environment`在空表上建立一个新的环境：`initial-env`  
    * 该环境此时只包含一些简单的常量(`true` `false` `nil`等等)， 需要在其上进行拓展：
        1. 定义`<object>`类：在*TOOL*中，`<object>`类是没有`superclass`和`slot`的原始类(`*primitive-class*`)，同时`<object>`被定义在`initial-env`这一最早的外围环境上。
                
                (define-variable! `<object> *primitive-class* initial-env)
        2. 添加`scheme-object-classes`: *TOOL*中把scheme的原始类定义为`<object>`的子类，通过`tool-eval`解析类定义进行拓展，同样scheme类也定义在`initial-env`上
        3. 添加`initial-procedures`：*TOOL*把scheme的一些基本操作转换为`generic-function`的形式，实现方法与上述类似。主要问题在于对gf添加`method`的过程：（在`proj2.scm`中有测试过程）
            1. 添加`method`时首先确定`generic-function`，这里采取的策略是，由于之前已经将gf加入到`initial-env`中，因此这里可以直接用tool-eval查找符号表以返回对应的gf。
                
                    gf的结构（以+为例）：
                    (generic-function + 
                    (((class <number> ((class <object> () ())) ()) 
                    (class <number> ((class <object> () ())) ())) 
                    . #<procedure:+>))
            2. 之后从`initial-procedure`中提取参数列表：  
                1. `(cadr entry)`返回的是类名形成的`list`，如`(<number> <number>)`  
                2. 以类名为参数查找符号表中对应的类信息： 
                    
                        class的结构
                        (class <number> 
                        ((class <object> () ())) ;superclass
                        ()) ; slots
           3. 通过`install-method-in-generic-function`将method插入到gf中
            
             
             