# 用construct 2制作射击小游戏

**Construct2是专为2D游戏设计的强大的突破性HTML5游戏创建者。它允许任何人建立游戏 - 不需要编码！它能够直接或间接的让你使用简单操作便可设计出一系列简单的小游戏。**

*对于一个像我一样对计算机刚入门的小白来说，面对这样一款construct 2，虽心生好奇、跃跃欲试，但还是会遇到了不少困难。今天就来给大家分享一下我用construct2做射击小游戏的经验吧！*

## 1.安装construct2
具体的操作很简单，到官网上下载并按照步骤一步步来就可以了！

[安装指南]<https://www.scirra.com/manual/2/installing>

## 2.新建
点击左上角的“File”,然后点击"New",再选择“New empty project”,就完成了。
![](http://ww1.sinaimg.cn/large/007jCw9lgy1fw2eefaqipj30cz0b8gm7.jpg)

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fw2ef3t5vmj30dc0djt9b.jpg)

## 3.明确布局的规格

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fw2endai84j30zh0pzmzo.jpg)

如上图我们可以看到右边的布局，白色部分就是整个游戏的布局，而虚线框内的画面就将是游戏时看到的画面。其大小都可以进行调整。

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fw2eqgh8z0j306z064jrl.jpg)

在布局中的空白位置左击鼠标，“属性栏”将呈现出“布局属性”。调整“Layout Size”即可对布局大小进行调整。

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fw2etmlfxcj30d90en74o.jpg)


![](http://ww1.sinaimg.cn/large/007jCw9lgy1fw2evfptgjj30ab0j0wf0.jpg)

点击右上角的"New project",就可在左边找到“Windows Size”,然后就可以调整虚线框的大小了。

## 4.改变背景图像
双击布局中的一个空白位置，这时候将出现一个“插入对象”对话框，双击“背景图层”对象以插入对象。

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fw2f1o3szzj30dw0bj75x.jpg)

这时候鼠标将变成一个十字光标。不管你最初将鼠标置于何处，这时候的你只要左击布局中的任何位置便可。随后图像编辑器便会打开，然后你便能够选择图像进行平铺。点击“打开”图标而输入图像。

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fw2f2jakdhj30bn0azjrr.jpg)

## 5.插入物体与添加图层

双击布局中的空白位置，再点击Sprite就可以插入物体，还可在左侧状态栏修改物体的属性。

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fw2f556tsoj30oe0km0to.jpg)

右侧layer栏中可创建新图层，锁定图层，使图层可视化，类似Photoshop的操作方法。

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fw2f9d2l2lj306x06rdfq.jpg)

## 6.添加行为

右击对象，即可添加行为。如红圈行为可让对象按方向键移动。

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fw2ff8x7tdj30c50c6q3y.jpg)

Construct2具有以下行为：

8 Direction movement: 这个行为可以让你实现给角色添加方向移动（方向键）的功能。

Bullet movement:这个行为让对象朝着它当前的角度移动

Scroll to：这个行为可以让运行时画布随着对象移来移去（滚动）。这个行为很适合于角色。

Bound to layout：这个行为可以防止对象离开画布区域。这个行为对于角色来说也很重要。

Destroy outside layout:当对象离开画布区域时，就将其销毁。

Fade:这个行为可以给对象添加淡出效果，用于爆炸等特效的消失。

## 7.事件
首先，在画布区域上方的选项卡上切换到Event sheet1事件编辑器面板，一个列表的事件被成为Event sheet事件表。游戏的不同部分可以拥有不同的事件表。
### 关于事件
Construct 2整个系统运作是基于事件系统，大多数显示器帧频为60帧/秒，为了匹配显示器达到平滑的显示效果，Construct 2也设置了差不多帧速率。所以事件表通常是一秒钟运行60次。每次都会更新屏幕相应发生变化的区域。事件表运行时的顺序为从上往下，所以靠上的事件先运行。

### 条件、动作、子事件
事件包含条件，测试某些条件是否满足，例如，Is spacebar down?(检测空格键是否按下)。如果条件满足了，那么事件的动作将会运行，例如，Create a bullet object创建一个子弹实例。当动作运行后，任何子事件也会运行，这样可以测试更多条件，运行更多的动作和更多的子事件等。使用该系统，我们可以为游戏或程序创建更多负责的功能。

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fw2fj3rtn7j30r70l1gmx.jpg)

*上图就是我做的射击小游戏的事件表*


#### 最后，只要按照步骤一步一步添加事件，就可以完成射击小游戏了！

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fw2fqi300bg312u0fihdt.gif)