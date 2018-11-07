# 硬件编程–机器指令编程实验报告

班级：软件工程教务2班

姓名：杨玲

学号：18342115

## 实验目标

1.理解冯·诺伊曼计算机的结构,了解 CPU 中各组件的作用

2.理解机器指令的构成

3.理解机器指令执行周期

4.了解并懂得初步使用汇编语言,汇编编写简单程序

5.通过比较,得出高级语言与机器语言的联系与区别 

## 实验步骤与结果

###  任务 1：简单程序
#### 1.实验步骤
(1)首先，在网页中输入数据
![](http://ww1.sinaimg.cn/large/007jCw9lgy1fwzn9zwyayj30gp09pt8n.jpg)

(2)其次，step after step，观察CPU是怎么运作的

a.LOD #3 ——   输入3
![](http://ww1.sinaimg.cn/large/007jCw9lgy1fwznt9h68yj30gn09o0so.jpg)

b.STO W    —— 存到地址W
![](http://ww1.sinaimg.cn/large/007jCw9lgy1fwznu43phej30gr09t0so.jpg)

c.LOD #7    ——输入7
![](http://ww1.sinaimg.cn/large/007jCw9lgy1fwznuw4z14j30go09o0so.jpg)

d.STO X     ——存到地址X
![](http://ww1.sinaimg.cn/large/007jCw9lgy1fwznwn3wy4j30gm09s0so.jpg)

e.ADD W     ——加上W（X+W)
![](http://ww1.sinaimg.cn/large/007jCw9lgy1fwznxp6h96j30gp09l3yg.jpg)

f.STO Y     ——X+W的结果存到地址Y
![](http://ww1.sinaimg.cn/large/007jCw9lgy1fwznze82okj30gp09q0so.jpg)

g.HLT       ——程序结束
![](http://ww1.sinaimg.cn/large/007jCw9lgy1fwzo0n2wa2j30gu09t0so.jpg)

#### 观察并回答下面问题：
(1)PC，IR 寄存器的作用。

PC: PC是专门用于在CPU取指令期间寻址程序存储器。PC总是保存着下一条要执行的指令的16位地址。 

IR:1.用来存放后续指令地址  
2.保存当前正在执行的一条指令   
3.保存将被存储的下一个数据字节的地址  
4.保存当前CPU所访问的主存单元的地址   

(2)ACC 寄存器的全称与作用。

全称:Accumulator(累加器) 

作用:主要用于完成数据的算术和逻辑运算，可以存放数据或中间结果。 

(3)用“LOD #3”指令的执行过程，解释Fetch-Execute周期。

a.PC 根据地址从RAM取出指令LOD #3 

b.指令传入IR，指令传入Decoder，无需取址，数字3传入MUX 

c.数字3传入ALU之后传入ACC 

(4)用“ADD W” 指令的执行过程，解释Fetch-Execute周期。

a.PC根据地址从RAM取出指令ADD W 

b.指令传入IR之后传入Decoder 

c.ALU从ACC中取值 

d.IR再次访问RAM中的W，从W中取值 

e.W的值读入ALU 

f.ALU执行加法，结果传入ACC 

(5)“LOD #3” 与 “ADD W” 指令的执行在Fetch-Execute周期级别，有什么不同。

LOD #3只需访问RAM一次,而ADD W需要两次访问RAM 

##### 点击“Binary”,观察回答下面问题

(1)写出指令 “LOD #7” 的二进制形式，按指令结构，解释每部分的含义。

00010100 00000111 

一个为步骤,另一个为操作数 

(2)解释 RAM 的地址。

只用于暂时存放程序和数据，一旦关闭电源或发生断电，其中的程序和数据就会丢失

(3)该机器CPU是几位的？（按累加器的位数）

16位

(4)写出该程序对应的 C语言表达。

int w = 3; int x = 7; int y = x + w; 


### 任务 2：简单循环

#### 1.实验步骤

(1)首先，在网页中输入数据
![](http://ww1.sinaimg.cn/large/007jCw9lgy1fwzq9mrk3uj30gp09mq2v.jpg)
(2)其次，step after step，观察CPU是怎么运作的

a.LOD X ——输入变量X
![](http://ww1.sinaimg.cn/large/007jCw9lgy1fwzqa8t4llj30gv09qwef.jpg)

b.SUB #1 ——减去1
![](http://ww1.sinaimg.cn/large/007jCw9lgy1fwzqavkdfuj30go09nwef.jpg)

c.JMZ 10 ——
![](http://ww1.sinaimg.cn/large/007jCw9lgy1fwzqbj17fmj30gp09rwef.jpg)

d.STO X ——存储到地址X
![](http://ww1.sinaimg.cn/large/007jCw9lgy1fwzqcnqbzlj30gm09qt8n.jpg)

e.JMP 0 ——

f.HLT ——程序结束
![](http://ww1.sinaimg.cn/large/007jCw9lgy1fwzqdc51fzj30gp09ot8n.jpg)

#### 观察并回答下列问题
（1） 输入程序Program 2，运行并回答问题：

a.用一句话总结程序的功能
b.写出对应的 c 语言程序

（2） 修改该程序，用机器语言实现 10+9+8+..1 ，输出结果存放于内存 Y

a.写出 c 语言的计算过程

b.写出机器语言的计算过程

c.用自己的语言，简单总结高级语言与机器语言的区别与联系。

联系:高级语言经编译可变为机械语言,都可以实现顺序，选择和循环 

区别：高级语言更接近人类语言,是给人看的 ; 机器语言是纯粹的二进制 数据,一般人看不懂(即是给机器看的,不是给人看的) 

## 实验小结

1.在对汇编语言的学习过程中,懂得了什么是汇编语言,机器语言,高级语言并知道了他们之间的联系与区别 

2.知道了什么是指令格式和指令周期 

3.了解到 CPU 各组件的作用,与 CPU 的运算过程 