#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//优化扫雷程序： 坐标周围没雷，可以实现展开。(递归)


void menu()
{
	printf("#############################\n");
	printf("#######   1. play   ######\n");
	printf("#######   0. exit   ######\n");
	printf("#############################\n");

}

void game()
{
	char mine[ROWS][COLS] = { 0 };//存放雷的信息
	char newmine[ROWS][COLS] = { 0 };//用于对于周围没有雷的打印
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息

	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//布置雷
	SetMine(mine, ROW, COL);

	CopyBoard(mine, newmine, ROWS, COLS);

	DisplayBoard(show, ROW, COL);
	//搜查雷
	FindBoard(mine, show, newmine, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//设置随机值
	do
	{
		menu();
		printf("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}