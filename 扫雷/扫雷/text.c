#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//�Ż�ɨ�׳��� ������Χû�ף�����ʵ��չ����(�ݹ�)


void menu()
{
	printf("#############################\n");
	printf("#######   1. play   ######\n");
	printf("#######   0. exit   ######\n");
	printf("#############################\n");

}

void game()
{
	char mine[ROWS][COLS] = { 0 };//����׵���Ϣ
	char newmine[ROWS][COLS] = { 0 };//���ڶ�����Χû���׵Ĵ�ӡ
	char show[ROWS][COLS] = { 0 };//����Ų�����׵���Ϣ

	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//������
	SetMine(mine, ROW, COL);

	CopyBoard(mine, newmine, ROWS, COLS);

	DisplayBoard(show, ROW, COL);
	//�Ѳ���
	FindBoard(mine, show, newmine, ROW, COL);
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//�������ֵ
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}