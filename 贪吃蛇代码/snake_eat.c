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



char map[12][12] =              //  直接打印游戏版面    
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

void put_money(void) {
    int i = 0, j = 0;
    srand(time(NULL));
    while (map[i][j] == 'X'||map[i][j] == 'Y'||map[i][j] == '*') {  //  如果生成的$所在的位置不当，则重新生成 
        i = rand()%10 + 1;       //  生成随机数使$出现 
        j = rand()%10 + 1;
    }
    map[i][j] = '$';
    return;
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

void turnDown() {
    int i, sx, sy;
    if ((snakeY[snakeLength - 1] + 1) == 11 || map[snakeY[snakeLength - 1] + 1][snakeX[snakeLength - 1]] == 'X') 
        gameover();
    else if (map[snakeY[snakeLength - 1] + 1][snakeX[snakeLength - 1]] == '$') {
        map[snakeY[snakeLength - 1] + 1][snakeX[snakeLength - 1]] = 'H';
		map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = 'X';
        snakeLength += 1;
        snakeY[snakeLength - 1] = snakeY[snakeLength - 2] + 1;
        snakeX[snakeLength - 1] = snakeX[snakeLength - 2];
        put_money();
        output();
    } 
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
    else if (map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1] - 1] == '$') {
        map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1] - 1] = 'H';
		map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = 'X';
        snakeLength += 1;
        snakeX[snakeLength - 1] = snakeX[snakeLength - 2] - 1;
        snakeY[snakeLength - 1] = snakeY[snakeLength - 2];
        put_money();
        output();
    } 
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
    else if (map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1] + 1] == '$') {
         map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1] + 1] = 'H';
		 map[snakeY[snakeLength - 1]][snakeX[snakeLength - 1]] = 'X';
         snakeLength += 1;
         snakeX[snakeLength - 1] = snakeX[snakeLength - 2] + 1;
         snakeY[snakeLength - 1] = snakeY[snakeLength - 2];
         put_money();
         output();
    } 
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

