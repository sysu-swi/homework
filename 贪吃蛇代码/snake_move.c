#include<stdio.h>
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
void output(void);
void gameover(void);



char map[13][13] =              //  直接打印游戏版面    
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

 /*伪代码    
      输出字符矩阵
	WHILE not 游戏结束 DO
		ch＝等待输入
		CASE ch DO
		‘A’:左前进一步，break 
		‘D’:右前进一步，break    
		‘W’:上前进一步，break    
		‘S’:下前进一步，break    
		END CASE
		输出字符矩阵
	END WHILE
	输出 Game Over!!! */
	
int main() {
    int flag = 1;
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

void output(void) {
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

/* 实现每一步的动作：
以turnup 为例，其他的类似：
IF position of head after movement is not wallsell or bodysell THEN
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

void turnDown() {
    int i, sx, sy;
    if ((snakeY[snakeLength - 1] + 1) == 11 || map[snakeY[snakeLength - 1] + 1][snakeX[snakeLength - 1]] == 'X') 
        gameover();
	else {
        map[snakeY[snakeLength - 1] + 1][snakeX[snakeLength - 1]] = 'H';
		map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = 'X';
        sx = snakeX[snakeLength - 1];
        sy = snakeY[snakeLength - 1];
        snakeY[snakeLength - 1] += 1;
        for (i = 0; i < snakeLength - 1; i++) {
            if (i == 0) map[snakeY[0]][snakeX[0]] = ' ';
            if (i == snakeLength - 2) {
                snakeX[i] = sx;
                snakeY[i] = sy;
            } 
			else {
            	snakeY[i] = snakeY[i + 1];
            	snakeX[i] = snakeX[i + 1];
            }
            map[snakeY[i]][snakeX[i]] = 'X';
        }
        output();
    }
    return;
}

void turnLeft() {
    int i, sx, sy;
    if ((snakeX[snakeLength - 1] - 1) == 0||map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1] - 1] == 'X') 
        gameover();
	else {
        map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1] - 1] = 'H';
		map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = 'X';
        sx = snakeX[snakeLength - 1];
        sy = snakeY[snakeLength - 1];
        snakeX[snakeLength - 1] -= 1;
        for (i = 0; i < snakeLength - 1; i++) {
            if (i == 0) map[snakeY[0]][snakeX[0]] = ' ';
            if (i == snakeLength - 2) {
               snakeX[i] = sx;
               snakeY[i] = sy;
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

void turnRight() {
    int i, sx, sy;
    if ((snakeX[snakeLength - 1] + 1) == 11 || map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1] + 1] == 'X') 
        gameover();
	else {
        map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1] + 1] = 'H';
		map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = 'X';
        sx = snakeX[snakeLength - 1];
        sy = snakeY[snakeLength - 1];
        snakeX[snakeLength - 1] += 1;
        for (i = 0; i < snakeLength - 1; i++) {
            if (i == 0) map[snakeY[0]][snakeX[0]] = ' ';
            if (i == snakeLength - 2) {
                snakeX[i] = sx;
                snakeY[i] = sy;
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

void gameover(void) {
	game = 1;
    printf("Game Over!\n");
    return; 
}
