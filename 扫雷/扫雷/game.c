#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

int win = 0;//����ȫ�ֱ�������i�ж���Ӯ
void InitBoard(char board[ROWS][COLS], int rows, int  cols, char set)//��ʼ������ 
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			board[i][j] = set;
		}
	}
}


void DisplayBoard(char board[ROWS][COLS], int row, int  col)//��ӡ���� 
{
	printf("---------ɨ����Ϸ----------\n");
	//��ӡ��һ�� ������ 
	printf("   ");
	for (int i = 1; i <= row; ++i)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (int i = 1; i <= row; ++i)
	{
		printf("%d: ", i);//��ӡ�к� 

		for (int j = 1; j <= col; ++j)//��ӡÿ��Ԫ�� 
		{
			if (board[i][j] == '0')  printf("  ");//�������ط���Χû���ף����ӡ�ո�
			else  printf("%c ", board[i][j]);
			if (board[i][j] == '*')  win++;
			//���ɨ�׳ɹ���ʱ����������ϵ�*���������������жϻ�ʤ
		}

		printf("\n");
	}

	printf("---------ɨ����Ϸ----------\n");
}


void SetMine(char board[ROWS][COLS], int row, int  col)//������ 
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//��������±�
		int y = rand() % col + 1;
		if (board[x][y] != '1')
		{
			board[x][y] = '1';//1������
			count--;
		}
	}
}


int  GetMine(char mine[ROWS][COLS], int x, int y)//�жϸ�������Χ�м�����
{
	//���������Ϊ�ַ�'1'���ۼ������ټ�ȥ8*��0����ɵõ���Χ�׵�����
	return (mine[x - 1][y] + mine[x - 1][y - 1] +
		mine[x][y - 1] + mine[x + 1][y - 1] +
		mine[x + 1][y] + mine[x + 1][y + 1] + mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0');
}

//��������
void CopyBoard(char mine[ROWS][COLS], char newmine[ROWS][COLS], int row, int col)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			newmine[i][j] = mine[i][j];
}

//�Ų���
void FindBoard(char mine[ROWS][COLS], char show[ROWS][COLS], char newmine[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		printf("������Ҫ�Ų������:>");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')//����
				printf("�ظ����룬����������\n");
			else if (mine[x][y] == '1')//��ը�����ӡ����
			{
				printf("���ź����㱻ը����\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else//��Ϊ�ף����ӡ�ø����ֲ�����������
			{
				int flag = 1;
				MakeBoard(mine, show, newmine, x, y, row, col, 1);
				DisplayBoard(show, ROW, COL);//��ӡչʾ������
			}
		}
		else
		{
			printf("����Ƿ�������������\n");
			break;
		}
		if (win == EASY_COUNT)//�ж�ʤ��
		{
			printf("��Ӯ��\n");
			DisplayBoard(mine, ROW, COL);
		}
		else//���¸�ֵwin
		{
			win = 0;
		}
	}
}

//�Ų�գ��ݹ飩 
void MakeBoard(char mine[ROWS][COLS], char show[ROWS][COLS], char newmine[ROWS][COLS], int x, int y, int row, int col, int flag)
{
	show[x][y] = GetMine(mine, x, y) + '0';//�������긳ֵ����Χ�׵ĸ��� 

	newmine[x][y] = '6';//���ĸ��Ƶ����̣���ֹ��������
	if (GetMine(mine, x, y) != 0)//������λ����Χû���ף���flag��Ϊ0��
		flag = 0;
	if (flag != 0)
	{//flagΪ0�򲻻��������//�жϿո���Χ
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