# 初步试水贪吃蛇

第一次自己尝试编写贪吃蛇，根据老师给的提示、上网搜集资料，我也总算自己写出贪吃蛇了。

贪吃蛇游戏可以分为以下必要几个部分：
1. 框架制作
2. 初始化定义一条蛇
3. 蛇的移动
4. 把蛇打印出来
5. 放置食物
6. 蛇吃食物（变长机制）
7. 蛇的生死（判定是否gameover）
8. 游戏结束收尾工作
9. 用户操作输入实现

搭好刚开始的框架很重要
```
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'

void turnUp(void);
void turnDown(void);
void turnLeft(void);
void turnRight(void);
void put_money(void);
void output(void);
void gameover(void);



char map[12][12] =              //打印游戏画面
      {"************",
      "*XXXXH     *",
      "*          *",
      "*          *",
      "*          *",
      "*          *",
      "*          *",
      "*          *",
      "*          *",
      "*          *",
      "*          *",
      "************"};
      
int snakeX[SNAKE_MAX_LENGTH] = {1, 2, 3, 4, 5};
int snakeY[SNAKE_MAX_LENGTH] = {1, 1, 1, 1, 1};
int snakeLength = 5;
int game = 0;

```

首先，写蛇移动的函数，蛇可以朝上下左右四个方向移动

```
/* 实现每一步的动作：
以turnup 为例，其他的类似：
IF position of head after movement is not wallsell or bodysell THEN
    IF position of head after movement is money THEN
    Put the head to the money
    ELSE
    Put the head up one step
    Set the last bodysell to be empty
    move every bodysell to the bodysell in front of it
    END IF
ELSE
    gameover
END IF  
*/

void turnUp() {
    int i, sy, sx;
    if ((snakeY[snakeLength - 1] - 1) == 0||map[snakeY[snakeLength - 1] - 1][snakeX[snakeLength - 1]] == 'X') 
        gameover();
	else if (map[snakeY[snakeLength - 1] - 1][snakeX[snakeLength - 1]] == '$') {
        map[snakeY[snakeLength - 1] - 1][snakeX[snakeLength - 1]] = 'H';
		map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = 'X';
        snakeLength += 1;
        snakeY[snakeLength - 1] = snakeY[snakeLength - 2] - 1;
        snakeX[snakeLength - 1] = snakeX[snakeLength - 2];
        put_money();
        output();
    } 
	else {
        map[snakeY[snakeLength - 1] - 1][snakeX[snakeLength - 1]] = 'H';
        sx = snakeX[snakeLength - 1];
        sy = snakeY[snakeLength - 1];
        snakeY[snakeLength - 1] -= 1;
        for (i = 0; i < snakeLength - 1; i++) {
            if (i == 0) map[snakeY[0]][snakeX[0]] = ' ';
            if (i == snakeLength - 2) {
                snakeY[i] = sy;
                snakeX[i] = sx;
            } 
			else {
                snakeX[i] = snakeX[i + 1];
                snakeY[i] = snakeY[i + 1]; 
            }
            map[snakeY[i]][snakeX[i]] = 'X';
        }
        output();
    }
    return;
}
```

然后是随机放置食物的函数  
其中的srand和rand函数是头文件stdlib.h内的

```
void put_money() {
    int i = 0, j = 0;
    srand(time(NULL));
    while (map[i][j] == 'X'||map[i][j] == 'Y'||map[i][j] == '*') {  //  如果生成的$所在的位置不当，则重新生成 
        i = rand()%10 + 1;       //  生成随机数使$出现 
        j = rand()%10 + 1;
    }
    map[i][j] = '$';
    return;
} 
```

输出游戏画面的函数 

每次输出前都要把之前的画面清空，此处用到system("cls")。
```

void output() {
    system("cls");   //  实现清屏的功能  每走一步清屏并将游戏版面输出 
    int i, j; 
    printf(" A -> left\n D -> right\n W -> up\n S -> down\n Then press enter.\n" );
    for (i = 0; i < 12; i++){
    	for (j = 0; j < 12; j++) {
    		printf("%c", map[i][j]);
    		if (j == 11) printf("\n");
		}
	}
    return;
}
```
还有游戏结束的函数，这与主函数密切相关
```
void gameover() {
	game = 1;
    printf("Game Over!\n");
    return; 
}
```

最后的最后，放上我的主函数
```
/* 伪代码：
While not gameover Do
    Get char
   IF char is A THEN
      turn left
   END IF
   IF char is D THEN
      turn right
   END IF
   IF char is W THEN
      turn up
   END If
   IF char is S THEN
      turn down
   END IF
END WHILE 
*/

int main() {
    int flag = 1;
    put_money();
    output();
    char ch;
    while (flag) {
        scanf("%c", &ch);
        if (ch == 'A' || ch == 'a') {
        	turnLeft(); 
        }
        if (ch == 'D' || ch == 'd') {
        	turnRight();
        }
        if (ch == 'W' || ch == 'w') {
        	turnUp();
        }
        if (ch == 'S' || ch == 's') {
        	turnDown();
        }
        if (game == 1)
        	flag = 0;
    }
    return 0;
} 

```

以上就是我贪吃蛇代码的主要分析，全部代码详见snake_move.c和snake_eat.c
