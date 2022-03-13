#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)//定义一行
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)//定义一行
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}


//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家走->\n");
	while (1)
	{
		printf("请输入下棋坐标->\n");
		scanf_s("%d %d", &x, &y);
		//判断输入坐标的合法性
		if (x > 0&&y > 0 && x <= row&&y <= col)
		{
			//坐标合法时判断坐标是否为空
			if (board[x-1][y-1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else//该坐标已被占用
			{
				printf("输入坐标已被占用，请重新输入->\n");
			}
			
		}
		else
		{
			printf("输入坐标不合法，请重新输入\n");
		}
	}
}
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑走->\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		//判断占用
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ');
			//棋盘未满
			return 0;
		}
	}
	return 1;//棋盘满了
}
char IsWin(char board[ROW][COL], int row, int col)
{
	//1. 玩家赢了 - *
	//2. 电脑赢了 - #
	//3. 平局     - Q
	//4. 游戏继续 - C
	
	//判断行、列、对角线
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//判断行
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
		//判断列
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
		//判断主对角线
		if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
		{
			return board[0][0];
		}
		//判断次对角线
		if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
		{
			return board[0][2];
		}

		//判断平局
	    //如果棋盘满了返回1， 不满返回0
		int ret = IsFull(board, row, col);
		if (ret == 1)
		{
			return 'Q';
		}
		else
			return 'C';	
}