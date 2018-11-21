# 用Python做数学
### Sympy库简介

SymPy一个用于符号型数学计算（symbolic mathematics）的Python库。它旨在成为一个功能齐全的计算机代数系统（Computer Algebra System，CAS），同时保持代码简洁、易于理解和扩展。SymPy完全是用Python写的，并不需要外部的库。

#### 选择Sympy库的原因在于：

* 免费：该库基于BSD开源许可，免费（free as in beer）且开源（free as in speech）；

* 基于Python：该库完全是用Python写就，并以Python作为该库操作语言；

* 轻量级：为了使Sympy简单易用，该库仅基于mpmath库（一个纯Python库，用于浮点运算）；

* 灵活性：除了用作交互工具，还可插入其他应用或软件拓展功能中。

## 一、使用Python做高数题目
1.求极限（详见《高等数学（上册）》第52页3.（5）

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fxffcduui7j312m0aiwi4.jpg)

- 在命令操作行输入
  >from sympy import *
- x趋近于0时求关于x的表达式的极限，先要定义x或者说给x赋值,操作如下： 
  >x=Symbol(‘x’) 
- 然后可以进行求极限操作,格式如下： 
  >limit(表达式，变量，趋近值） 
- 具体操作见图 

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fxffeqfnbkj30ct03jjra.jpg)