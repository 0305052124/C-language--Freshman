#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//��ʼ������
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
//��ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)//����һ��
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
			for (j = 0; j < col; j++)//����һ��
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


//�������
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����->\n");
	while (1)
	{
		printf("��������������->\n");
		scanf_s("%d %d", &x, &y);
		//�ж���������ĺϷ���
		if (x > 0&&y > 0 && x <= row&&y <= col)
		{
			//����Ϸ�ʱ�ж������Ƿ�Ϊ��
			if (board[x-1][y-1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else//�������ѱ�ռ��
			{
				printf("���������ѱ�ռ�ã�����������->\n");
			}
			
		}
		else
		{
			printf("�������겻�Ϸ�������������\n");
		}
	}
}
//��������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("������->\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		//�ж�ռ��
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
			//����δ��
			return 0;
		}
	}
	return 1;//��������
}
char IsWin(char board[ROW][COL], int row, int col)
{
	//1. ���Ӯ�� - *
	//2. ����Ӯ�� - #
	//3. ƽ��     - Q
	//4. ��Ϸ���� - C
	
	//�ж��С��С��Խ���
	int i = 0;
	for (i = 0; i < row; i++)
	{
		//�ж���
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
		//�ж���
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
		//�ж����Խ���
		if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
		{
			return board[0][0];
		}
		//�жϴζԽ���
		if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
		{
			return board[0][2];
		}

		//�ж�ƽ��
	    //����������˷���1�� ��������0
		int ret = IsFull(board, row, col);
		if (ret == 1)
		{
			return 'Q';
		}
		else
			return 'C';	
}