#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

int win = 0;//设置全局变量用于i判断输赢
void InitBoard(char board[ROWS][COLS], int rows, int  cols, char set)//初始化棋盘 
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			board[i][j] = set;
		}
	}
}


void DisplayBoard(char board[ROWS][COLS], int row, int  col)//打印棋盘 
{
	printf("---------扫雷游戏----------\n");
	//打印第一行 行数字 
	printf("   ");
	for (int i = 1; i <= row; ++i)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (int i = 1; i <= row; ++i)
	{
		printf("%d: ", i);//打印列号 

		for (int j = 1; j <= col; ++j)//打印每行元素 
		{
			if (board[i][j] == '0')  printf("  ");//如果这个地方周围没有雷，则打印空格
			else  printf("%c ", board[i][j]);
			if (board[i][j] == '*')  win++;
			//最后扫雷成功的时候如果棋盘上的*和雷数量相等则可判断获胜
		}

		printf("\n");
	}

	printf("---------扫雷游戏----------\n");
}


void SetMine(char board[ROWS][COLS], int row, int  col)//布置雷 
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//生成随机下标
		int y = rand() % col + 1;
		if (board[x][y] != '1')
		{
			board[x][y] = '1';//1代表雷
			count--;
		}
	}
}


int  GetMine(char mine[ROWS][COLS], int x, int y)//判断该坐标周围有几个雷
{
	//如果是雷则为字符'1'，累计数量再减去8*‘0’则可得到周围雷的数量
	return (mine[x - 1][y] + mine[x - 1][y - 1] +
		mine[x][y - 1] + mine[x + 1][y - 1] +
		mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0');
}

//复制棋盘
void CopyBoard(char mine[ROWS][COLS], char newmine[ROWS][COLS], int row, int col)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			newmine[i][j] = mine[i][j];
}

//排查雷
void FindBoard(char mine[ROWS][COLS], char show[ROWS][COLS], char newmine[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		printf("请输入要排查的坐标:>");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')//判重
				printf("重复输入，请重新输入\n");
			else if (mine[x][y] == '1')//被炸死则打印棋盘
			{
				printf("很遗憾，你被炸死了\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else//不为雷，则打印该格数字并且延申棋盘
			{
				int flag = 1;
				MakeBoard(mine, show, newmine, x, y, row, col, 1);
				DisplayBoard(show, ROW, COL);//打印展示用棋盘
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
			break;
		}
		if (win == EASY_COUNT)//判断胜负
		{
			printf("你赢了\n");
			DisplayBoard(mine, ROW, COL);
		}
		else//重新赋值win
		{
			win = 0;
		}
	}
}

//排查空（递归） 
void MakeBoard(char mine[ROWS][COLS], char show[ROWS][COLS], char newmine[ROWS][COLS], int x, int y, int row, int col, int flag)
{
	show[x][y] = GetMine(mine, x, y) + '0';//给该坐标赋值，周围雷的个数 

	newmine[x][y] = '6';//更改复制的棋盘，防止后续错误
	if (GetMine(mine, x, y) != 0)//如果这个位置周围没有雷，则将flag变为0，
		flag = 0;
	if (flag != 0)
	{//flag为0则不会继续延申//判断空格周围
		if (x > 1 && newmine[x - 1][y] == '0')
			MakeBoard(mine, show, newmine, x - 1, y, row, col, flag);
		if (x < row && newmine[x + 1][y] == '0')
			MakeBoard(mine, show, newmine, x + 1, y, row, col, flag);
		if (y < col && newmine[x][y + 1] == '0')
			MakeBoard(mine, show, newmine, x, y + 1, row, col, flag);
		if (y > 1 && newmine[x][y - 1] == '0')
			MakeBoard(mine, show, newmine, x, y - 1, row, col, flag);

		/*if (x > 1 && newmine[x - 1][y-1] == '0')
			MakeBoard(mine, show, newmine, x - 1, y-1, row, col, flag);
		if (x < row && newmine[x + 1][y] == '0')
			MakeBoard(mine, show, newmine, x + 1, y, row, col, flag);
		if (y< col  && newmine[x-1][y + 1] == '0')
			MakeBoard(mine, show, newmine, x-1, y + 1, row, col, flag);
		if (y>1 && newmine[x+1][y - 1] == '0')
			MakeBoard(mine, show, newmine, x+1, y - 1, row, col, flag);*/
	}
}