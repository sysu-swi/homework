# 用Python做数学
### Sympy库简介

SymPy一个用于符号型数学计算（symbolic mathematics）的Python库。它旨在成为一个功能齐全的计算机代数系统（Computer Algebra System，CAS），同时保持代码简洁、易于理解和扩展。SymPy完全是用Python写的，并不需要外部的库。

#### 选择Sympy库的原因在于：

* 免费：该库基于BSD开源许可，免费（free as in beer）且开源（free as in speech）；

* 基于Python：该库完全是用Python写就，并以Python作为该库操作语言；

* 轻量级：为了使Sympy简单易用，该库仅基于mpmath库（一个纯Python库，用于浮点运算）；

* 灵活性：除了用作交互工具，还可插入其他应用或软件拓展功能中。

## 一、使用Python做高数题目
#### 1.求极限（详见《高等数学（上册）》第52页3.（5）

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fxffcduui7j312m0aiwi4.jpg)

- 在命令操作行输入
  >from sympy import *
- x趋近于0时求关于x的表达式的极限，先要定义x或者说给x赋值,操作如下： 
  >x=Symbol(‘x’) 
- 然后可以进行求极限操作,格式如下： 
  >limit(表达式，变量，趋近值） 
- 具体操作见图 

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fxffeqfnbkj30ct03jjra.jpg)

## 二、使用Python做线代题目

#### 1、求矩阵的逆（详见《线性代数及其应用》第126页第一题）

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fxfh1llpvvj31n70dmagp.jpg)

- 在命令操作行输入
  >from numpy import *
- 先输入矩阵A,操作如下： 
   >A = matrix([[8,6],  
   >... [5,4]])
- 然后可以查看矩阵A,格式如下： 
   > A  

- 输出结果：
   > matrix([[8, 6],  
            [5, 4]])
- 然后直接求A的逆，操作如下：
    >A.I  
- 输出了结果：
    >matrix([[ 2. , -3. ],  
        [-2.5,  4. ]])
- 具体操作见图 

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fxfhakwo30j30cr067jre.jpg)

这与我们自己进行手算的结果完全相同

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fxfhbhckxoj30k303u74a.jpg)

####  2.求矩阵相乘的积（详见《线性代数及其应用》第116页第5题）

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fxfhriv2p1j31xc0m8wrl.jpg)

- 在命令操作行输入
  >from numpy import *
- 先输入矩阵A、B，具体操作如上题,在此就不赘述。
- 然后直接求A、B相乘的积，操作如下：
    >dot(A,B)  
- 输出了结果：
    >matrix([[ -7 , 4 ],  
            [7,-6],  
            [12, -7 ]])
- 具体操作见图 

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fxfhw497lcj30dg0be0sy.jpg)

这与我们自己进行手算的结果完全相同

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fxfhyspadjj30re09gaae.jpg)
