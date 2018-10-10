来自新手的新手平台游戏制作教程（误导向）
# 综述  （百度搜索Ashley，可以找到大神的教学资料，本篇技术博客灵感以及部分图片来源于大神的入门教程） （纯手打，原创）
  突然让我们这些计算机小白做游戏，感受到了软件工程导论这门课深深的恶意。但是在自己按照教程亲自操作一遍后，却又发现这个任务似乎不是想象中的艰巨。 
Construct2是一个很基础的游戏制作软件，能制作出在HTML5上运行的平面游戏，也就和我们平时所说的小游戏差不多。作为一个初入游戏制作大门的新手，既不需编
程，又没有复杂的特殊操作，的确是上手专用的好软件。话不多说，下面我就描述一下我是如何入门的吧。
## 步骤讲解
### 准备阶段
1. 下载并安装construct2  网上资源有很多，这个软件有三个版本，我们若不是商业用，就下载免费版就行。
2. 新建文件  和大多数软件一样，只需要打开软件，点击左上角的File-new即可
![](https://www.scirra.com/images/articles/filenew.png)
3. 修改文件规格  为了让游戏界面不那么狭小，我们要先在左侧的属性栏中适当修改，讲LayOut Size（布局属性）修改为4000,2048
![](https://www.scirra.com/images/articles/layoutsize.png)
4. 背景的制作 界面做好后，我们再进行背景的制作。双击空白界面，选择指令框中的平铺背景，然后随意点击任意空白处，然后导入已有的背景图像，在关闭图像编辑
器，我们的背景就能出现了，这时你会发现我们的背景并没有完全占据整个界面，所以我们就要在属性栏中修改属性，同样的现将布局属性修改为4000,2048 ，然后再将
位置（position）设置为0,0 ，这样我们的背景就完成了
![](https://www.scirra.com/images/articles/tiledbackground.png)
![](https://www.scirra.com/images/articles/loadimagefromfile.png)
![](https://www.scirra.com/images/articles/tiledbgsize.png)
![](https://www.scirra.com/images/articles/tiledplatformerbg.png)
5. 添加分层 做游戏必须要分层，这样我们的角色才能在游戏中有条不紊的运动。为了添加层，我们先在右侧的项目栏（project）中选中layers（层），然后就可以看
见我们自己的层，重命名为Background，然后锁定他，再添加一个新的层，命名为Main，并选中它作为主要操作的对象。
![](https://www.scirra.com/images/articles/layerstab.png)
![](https://www.scirra.com/images/articles/layersbar.png)
完成上面的步骤后我们就可以开始自己创造游戏的关键部分了，添加我们自己想要的组分
### 地图制作
1. 添加地图 作为一个平台游戏，地图是十分重要的，它是我们游戏的主角行动的基础。为了添加地图，我们要像上面添加背景一样，先双击空白界面，弹出选择框之
后，选择精灵（Sprite），然后又进入了图形编辑器。右击下方的空白界面，选择导入精灵条,并选中自己准备好的地图模块。这时，会弹出一个指令框，需要你输入两
个数字，这两个数字的意思是要将你选择的图片分成A * B块，然后一块一帧，这时我们就输入两个12，确定后我们就得到了拆分后的144帧图像。当然这个时候，我们要
去掉初始的空白帧，并将地图的属性栏中的速度改为0，使我们的地图固定。然后关闭图形编辑器，我们的地图就成功生成了，但是在层上只显示出了原始的图像，这是远
远不够的，为了得到整个平台游戏全部的地图，我们必须进行下一步操作。
![](https://www.scirra.com/images/articles/importspritestrip.png)
![](https://www.scirra.com/images/articles/importingtilemap.png)
![](https://www.scirra.com/images/articles/spritetile.png)
2. 构建完整地图 我们为了得到整个游戏的全部地图，必须对我们得到的原始图块进行操作。按下键盘control键，并左击图块拖动它可以得到一个复制的图像，连续操
作后，我们的地图便做好了原型。在construct2中，精灵文件都有原始属性Initial frame，这是指他的显示帧，我们观察属性栏可以看见，我们的图块该属性都是0
，0这时我们略加修改该属性，就可以得到每块都不同的图像。
![](https://www.scirra.com/images/articles/threetiles.png)
3. 将图像对齐 单击上侧的View指令，勾选snap to grid(对其网格)，由于我们的图像都是128* 128的格式，所以我们的图块啊能很好对齐，这样我们的背景就已经
完全做好了。
![](https://www.scirra.com/images/articles/snaptogrid.png)
### 角色制作
1. 导入角色 终于到重头戏了，角色是游戏的核心，但是作为新手入门教程，我在这里并不准备介绍复杂的角色能力的制作，只是教授最简单的能完成移动和跳跃的简单
操作的角色制作方法。首先我们要和上面一样导入角色，然后我们将属性栏的速度设置为9，开启循环，再之后要为他设置原点，单击设置原点和图像点，选择自动对齐角
色下方，然后将操作应用于整个动画。这之后我们预览时就会发现我们的角色在上下震动，表示我们已经完成了第一步。
![](https://www.scirra.com/images/articles/playercropped.png)
![](https://www.scirra.com/images/articles/origintool.png)
![](https://www.scirra.com/images/articles/applytowholeanimation.png)
2. 添加行为 由于我们不能直接控制角色的部分行为（容易出错），我们在这里先添加一个新的精灵，一个蓝色图块，和上面的操作一样。关闭图像编辑器后我们将图块
移动到和角色重合，并调节他的大小和角色差不多，然后将他的属性调为不可见。现在我们可以将角色的行为添加给它了。还是在属性栏，点击behavior栏中的添加，选
择添加“平台”和“滚动”行为，这样我们就可以通过它来控制角色的移动了。除此之外，我们为了让角色能够在地图上移动而不掉下去，我们还要为地图添加solid（坚
硬）的behavior。
![](https://www.scirra.com/images/articles/playercollisionbox.png)
![](https://www.scirra.com/images/articles/addplayerboxbehavior.png)
![](https://www.scirra.com/images/articles/platformbehavior.png)
![](https://www.scirra.com/images/articles/switchtoeventsheet.png)
3. 将辅助精灵的行为附加给角色 这是核心步骤，我们需要切换到事件窗口，双击添加系统操作，并选择每一刻（Every tick），再在这个事件中添加行动，选择角色-
Set position to another object ,之后在弹出来的选择框中依次选择辅助精灵和0即可，这样我们就成功地将辅助精灵上有的动作添加给了角色。
  ![标准图示](https://www.scirra.com/images/articles/setpositionaction.png)
  ![标准图示](https://www.scirra.com/images/articles/setpositionevent.png)
 ## 小结
  依次完成好上面步骤之后，我们便做出了一个极为简单的平台游戏，但作为一个初入计算机大门的小白来说，其实已经相当不易。
这个任务虽然简单，但是却为我们展现了计算机世界的冰山一角，计算机的世界如此美妙，技术成熟后我们都能在这个世界中构建自己的宏图，所以让我们一起继续努
力学习计算机技术吧，争取早日成为计算机界的达人。
![我的效果演示](https://imgsa.baidu.com/forum/w%3D580%3B/sign=e345bab59d529822053339cbe7f17acb/5243fbf2b2119313151879c268380cd791238d6d.jpg)


# HTML5游戏的策划与设计（绝对原创，纯手打）
## 游戏策划
### 创作动机（Creative Motivation）
   在经过游戏教程学习了HTML5游戏制作后，跃跃欲试，准备自己做出一个简易而又有趣的小游戏。
### 目标市场（Targeted Market）
   该游戏为自制娱乐练习，无目标市场。
### 楔子（Setting）
   很久很久以前，有一个强壮的战士，由于实力超群，他逐渐积累声望，并受到了国王的赏识，他立下了赫赫战功，为国家的安定做出了汗马功劳，在最后一场战争结束  
   后，国家实现了统一。这天晚上，国王邀请他参加盛宴，宴会上当战士喝下国王赐下的美酒后，突然全身出血倒地，这时战士才发现了国王邪恶的本质。为了复仇，战士 
   与死神签订了邪恶的契约，他在死神的帮助下复活，不过成为了一个丑陋的怪物（monster），国王立即派遣士兵去追杀它。战士能否逃脱士兵的追击，逃离城堡呢？   
### 玩法（Gameplay）
   玩家击败所有士兵或到达出口任务完成。玩家无法到达出口任务失败。玩家使用键盘方向键来控制战士移动，目前具有少数特殊能力，可以二段跳，玩家接触士兵并且位
   于士兵正上方可以发动死亡践踏消灭士兵，否则会发动圣光庇护全身闪光而避免受伤。
### 人设与道具（Game Sprites）
 1. Player ： 战士（Monster）。与死神签订条约后，战士的能力得到了强化，他有无限的体力，并有死亡践踏和圣光守护以及二段跳三种能力。
 2. Enemies ： 士兵（Soldiers）。士兵具有巡逻的能力，他们分布广泛，四处巡逻，有条不紊，生命力极强，只有死亡践踏才能消灭他们。
## 游戏设计
### Object（事物）：战士
   1. Attributes（属性）：图片，位置
   2. Collaborator（合作者）：精灵
   3. Events & Actions（事件及行为）移动，键盘方向键（On every tick）
   4. 死亡践踏（从正上方踩到士兵），士兵被消灭
   5. 神圣闪光（没从正上方，但接触到了士兵），战士闪光但士兵不被消灭
   6. 死亡（战士掉落），战士被消灭
### Object(事物)：士兵
   1. Attributes（属性）：图片，位置
   2. Collaborator（合作者）：无
   3. Events & Actions(事件及行为)：碰撞，反弹


![效果演示](https://imgsa.baidu.com/forum/w%3D580/sign=d0336942b7a1cd1105b672288913c8b0/53a93c355982b2b7f84db4b63cadcbef74099be5.jpg)
