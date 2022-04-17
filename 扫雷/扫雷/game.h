#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//���̴�С
#define ROW 9
#define COL 9
//��ֹԽ�������
#define ROWS ROW+2
#define COLS COL+2
//�׵�����
#define EASY_COUNT 10

//��ʼ������
void InitBoard(char board[ROWS][COLS], int rows, int  cols, char set);

//��ӡ���̣���q�����жϴ�ӡ0��ʱ����������ӡ���Ǵ�ӡ�ո�
void DisplayBoard(char board[ROWS][COLS], int row, int  col);

//������
void SetMine(char board[ROWS][COLS], int row, int  col);

//�Ų���
void FindBoard(char mine[ROWS][COLS], char show[ROWS][COLS], char newmine[ROWS][COLS], int row, int col);

//�Ҷ�Ӧ���긽���м�����
int  GetMine(char mine[ROWS][COLS], int x, int y);

//�ж���Χ�ж�����
//��ΪҪ�����ӡ�����ҵ�һ�������ǿշ���ʱ��Ȼ��ӡ��������flag�жϣ�
void MakeBoard(char mine[ROWS][COLS], char show[ROWS][COLS], char newmine[ROWS][COLS], int x, int y, int row, int col, int flag);

//��������
void CopyBoard(char mine[ROWS][COLS], char newmine[ROWS][COLS], int row, int col);