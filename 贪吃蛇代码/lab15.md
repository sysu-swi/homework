# 智能蛇的学习心得

*之前在网上看到这副很火的智能蛇动画,这大概就是超高级版的智能蛇了。所以最近，我在自己思考的基础上，查询了相关资料，并请教学长学姐，终于也写出了一个不是很智能的智能蛇。*

![](http://ww1.sinaimg.cn/large/007jCw9lgy1fy33iqqvp6g308b08bne4.gif)


有了上一个基本框架的贪吃蛇，智能蛇的实现其实只需要写出一个函数替代getinp（）函数并每秒执行一次即可。

下面着重讲下搜索策略 

### 方案1.0 

在一个矩形中，每一时刻有一个食物，贪吃蛇要在不撞到自己的条件下， 找到一条路(未必要最优)，然后沿着这条路运行，去享用它的美食显然这个仅仅一个bfs即可实现，此蛇很容易被自己直接绕住。

### 方法2.0 

一开始，蛇很短(初始化长度为1)，它看到了一个食物， 使用bfs得到矩形中每个位置到达食物的最短路径长度。在没有蛇身阻挡下， 就是曼哈顿距离。然后，我要先判断一下，贪吃蛇这一去是否安全。 所以我需要一条虚拟的蛇，它每次负责去探路。如果安全，才让真正的蛇去跑。 当然，虚拟的蛇是不会绘制出来的，它只负责模拟探路。

那么， 怎么定义一个布局是安全的呢？ 

如果仔细观察前面的动画， 会发现即使到最后蛇身已经很长了，它仍然没事一般地走出了一条路。而且， 是跟着蛇尾走的！嗯，这个其实不难解释，蛇在运动的过程中，消耗蛇身， 蛇尾后面总是不断地出现新的空间。蛇短的时候还无所谓，当蛇一长， 就会发现，要想活下来，基本就只能追着蛇尾跑了。在追着蛇尾跑的过程中， 再去考虑能否安全地吃到食物。

我们根据以上推出策略： 
 - 无食物是寻找离尾部最远的路径移动 
 - 有食物时，派出分身沿着最短路吃，之后判断能否走向尾部，若不能则继续追踪尾巴，当超过100步（全图必定可遍历）后判定无解直接去吃 
 - 若无食物也没有尾部，则自动走向空白处大的方向

以下是本人最后写出的代码

```
#include<stdio.h>
#include<time.h>
#define FOR(i,j,k) for(i=j;i<=k;++i)
#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'
#define mal 0x7fffffff

int life = 1;
int snakey[100] = { 5,4,3,2,1 };
int snakex[100] = { 1,1,1,1,1 };
int d[1000][1000];
char map[12][12] = { "************",
"*XXXXH     *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"*          *",
"************" };
int fx, fy, lx, ly;
int len = 5;
int mx,my;
int diffcuilty;
void pm();
int n, m, w, h;//W 1 ;A 2 ;S 3 ;D 4
char cp[12][12];
int f[12][12];
int qx[1000],qy[1000];
int qboo[12][12];
int dxx[5]={0,0,-1,0,1};
int dyy[5]={0,1,0,-1,0};

void bfs(int lx,int ly){
    int ux=lx,uy=ly;int tx,ty;
    int i,j,k;
    int be=0,en=0;
    FOR(i,1,10)
        FOR(j,1,10){
                qboo[i][j]=1;
                f[i][j]=mal;
            }
    qx[0]=lx;qy[0]=ly;qboo[lx][ly]=0;
    f[lx][ly]=0;
    while(be<=en) {
        k=be;be++;
        ux=qx[k];
        uy=qy[k];
        qboo[ux][uy]=0;
        FOR(i,1,4){
            tx=dxx[i]+ux;
            ty=dyy[i]+uy;
            if ((cp[tx][ty]==' '||cp[tx][ty]=='H')&&qboo[tx][ty]){
                    f[tx][ty]=f[ux][uy]+1;
                    en++;
                    qx[en]=tx;
                    qy[en]=ty;
                }
        }
    }
}
void cop(){//复制目前状态
    int i,j;
    FOR(i,0,11)
        FOR(j,0,11)
            cp[i][j]=map[i][j];
}

int ddd(){//求方向解
    cop();int i,j,k=10000;int l;
    bfs(mx,my);
    if (f[fx][fy]!=mal) {
            FOR(i,1,4)
                if (f[fx+dxx[i]][fy+dyy[i]]<k){
                        k=f[fx+dxx[i]][fy+dyy[i]];
                        j=i;
                    }
            return j;
        }
    else{
        bfs(lx,ly);
        k=-1;
        FOR(i,1,4)
                if (f[fx+dxx[i]][fy+dyy[i]]>k&&f[fx+dxx[i]][fy+dyy[i]]!=mal){
                        k=f[fx+dxx[i]][fy+dyy[i]];
                        j=i;
                    }
            return j;
    }
}

void CreateTheBackground(){
    int i, j, k;
    w = 10; h = 10;
    FOR(i, 1, w)
        FOR(j, 1, h){
        if (map[i][j] != '*') {
            map[i][j] = ' ';
            d[i][j] = 0;
        }
    }
    FOR(i, 1, 4) {
        map[i][10] = 'X';
        d[i][10] = 4;
    }
    fx = 5; fy = 10;
    d[5][10] = 4;
    map[5][10] = 'H';
    lx = 1; ly = 10;
    FOR(i, 0, h + 1) { 
        map[0][i] = '*'; 
        map[w + 1][i] = '*'; 
    }
    FOR(i, 0, w + 1) { 
        map[i][0] = '*'; 
        map[i][h + 1] = '*'; 
    }
    pm();
}
void pm(){
    srand(time(NULL));
    int i, j;
    i = rand() % w + 1;
    j = rand() % h + 1;
    while (map[i][j] != ' ') {
        i = rand() % w + 1;
        j = rand() % h + 1;
    }
    mx=i;
    my=j;
    map[i][j] = '$';
}
int getinp(){//W 1 ;A 2 ;S 3 ;D 4
    int start = clock();
    int dr;
    while (clock() - start <= 1000);
    dr=ddd();
    return dr;
}
void pp(){
    int i, j;
    system("cls");
    for (i = h + 1; i >= 0; --i) {
        FOR(j, 0, w + 1)
            printf("%c", map[j][i]);
        printf("\n");
    }
}
void dead(){
    int t;
    printf("Game Over!!!"); //getchar();
}
void movement(int dr){
    int tx, ty, t;
    d[fx][fy] = dr;
    int bj = 0;
    map[fx][fy] = 'X';

    if (dr == 1) fy++;
    if (dr == 2) fx--;
    if (dr == 3) fy--;
    if (dr == 4) fx++;
    if (map[fx][fy] == '$')  
        bj = 1; 
    if (map[fx][fy] == 'X' || map[fx][fy] == '*') {     life = 0; 
        return;
    }
    map[fx][fy] = 'H';
    if (bj) {
        pm();//fang zhi jian qian
        len++;
        return;
    }

    t = d[lx][ly];
    map[lx][ly] = ' ';
    if (t == 1) ly++;
    if (t == 2) lx--;
    if (t == 3) ly--;
    if (t == 4) lx++;
}
int u = 1;
void done(){//W 1 ;A 2 ;S 3 ;D 4
    int d = getinp();
    if (d != 0) u = d;
    movement(u);
    pp();
}
int main(){
    CreateTheBackground();
    pp();//输出
    int ch;
    int las=4;
    while (life){
        ch = getinp();//shu ru
        if (!(ch>=1&&ch<=4) ) ch=las;
        las=ch;
        switch (ch){//根据输入的方向移动
            case 1:movement(1); break;
            case 2:movement(2); break;
            case 3:movement(3); break;
            case 4:movement(4); break;
        }
        if (life) pp();
    }
    dead();
    return 0;
}
```