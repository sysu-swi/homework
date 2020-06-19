# HTML5游戏设计与制作

*在之前，我们学习了如何用Construct 2来制作一个简单小游戏，而学无止境，因此本篇主要记录了我进一步利用Construct 2来设计游戏的过程。*

## 一、游戏策划

*一个好的游戏设计过程，游戏的策划是至为重要的。
为了更好地描述一个游戏的制作过程，这里给出了本文实例游戏的概念（concept）文档。*

#### 1.创作动机
因软导作业要求而尝试用Construct 2制作小游戏

#### 2.目标市场
小学生

#### 3.游戏故事：
>楔子(Setting)：公元2050年，六角星人因原本所在的星球资源枯竭而选择大举入侵地球，想要统治地球，占有地球资源。为了保护地球的安全，作为飞虎队的队长，你挺身而出，踏上了保护地球的征程。

#### 4.玩法(Gameplay)
玩家需消灭尽可能多的UFO,每架UFO被子弹射中三次才会爆炸。玩家被UFO撞到，任务失败。玩家通过操作方向键来进行移动，通过空格键来发射子弹。

#### 5.人设与道具（Game Sprites）：
Player：操作方向键来移动，通过空格键发射子弹。需消灭尽可能多的UFO。被UFO撞到即失败。

UFO: 需被3发子弹打中才会爆炸。

![](images\lab08\1.gif)

上图是gif的动画成果

## 二、游戏设计

1.
>Object:子弹  
Attribute:图片,位置  
Collaborator：UFO  
Events & Actions：碰撞 & 销毁自己

2.
>Object:UFO   
Attribute:图片,位置  
Collaborator：子弹  
Events & Actions：碰撞 & 销毁自己

3.
>Object:飞机  
Attribute:图片,位置  
Collaborator：子弹  
Events & Actions：发射子弹

4.
>Object:再来一次  
Attribute:图片,位置  
Collaborator：无  
Events & Actions：从头开始

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fw2fj3rtn7j30r70l1gmx.jpg)

## 三、小结

运用面向对象的分析设计方法来设计并制作了这个小游戏，虽然过程并不十分顺利，但也从中学到了很多。面向对象的编程方法的确很有用。游戏中的对象有什么，然后没有对象都有什么行为，这是我现在一做小游戏就会想到的问题，可见这种思想的影响之深啊！学无止境，继续努力吧，希望以后能做出更多更好的小游戏。