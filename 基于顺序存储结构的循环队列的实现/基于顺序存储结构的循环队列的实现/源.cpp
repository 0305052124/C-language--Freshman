#define _CRT_SECURE_NO_WARNINGS 1
//Queue On Sequence Structure
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE  100
#define FALSE   0
#define TRUE    1

typedef int DataType; //����Ԫ�����Ͷ���
DataType x;
typedef struct
{
	DataType elem[MAXSIZE];
	int  rear;
	int  front;
	int  count;
}SeqQueue;


void InitQueue(SeqQueue* Q);//��ʼ������ 
int IsEmpty(SeqQueue* Q);//�п� 
int IsFull(SeqQueue* Q);//���� 
int EnterQueue(SeqQueue* Q, DataType x); //������ 
int DeleteQueue(SeqQueue* Q, DataType* x); //������ 
void PrintQueue(SeqQueue* Q);  //�Ӷ�ͷ��ӡ����β
void PrintQueue1(SeqQueue* Q);  //�Ӷ�β��ӡ����ͷ
 

int main()
{
	SeqQueue Q;  //����һ������Q 
	char sel = ' ';
	while (sel != '0')
	{
		printf("------����(ѭ��˳��洢�ṹ)��ʾϵͳ-------\n");
		printf("   �汾:1.0   ����:���� ����:2022-04-14\n");
		printf("------------------------------------------\n");
		printf("       1.��ʼ������\n");
		printf("       2.�����в���\n");
		printf("       3.�����в���\n");
		printf("       4.��ӡ���г���\n");
		printf("       5.��ӡ����(�Ӷ�ͷ����β)\n");
		printf("       6.�����Ļ\n");
		printf("       7.��ӡ����(�Ӷ�β����ͷ)\n");
		printf("       0.�˳�ϵͳ\n");
		printf("������ѡ��[0-7]:");
		sel = getchar();
		switch (sel)
		{
		case '1':
			printf("��ʼ������.\n");
			InitQueue(& Q);//��ʼ������ 
			system("pause");  
			break;
		case '2':
			printf("�����в���.\n");
			printf("������Ҫ����е�Ԫ�أ�");
			scanf_s("%d", &x);
			EnterQueue(&Q, x); //������ 
			PrintQueue(&Q);//��ӡ
			system("pause"); 
			break;
		case '3':
			printf("�����в���.\n");
			DeleteQueue(&Q,&x);
			PrintQueue(&Q);//��ӡ
			system("pause"); 
			break;
		case '4':
			printf("��ӡ���г��Ȳ���.\n");
			printf("���г���Ϊ%d\n",Q.count);
			system("pause");  
			break;
		case '5':
			printf("��ӡ���в���(�Ӷ�ͷ����β��).\n");
			PrintQueue(&Q);
			system("pause"); 
			break;
		case '6':
			system("cls");
			break;
		case '7':
			printf("��ӡ���в���(�Ӷ�β����ͷ).\n");
			PrintQueue1(&Q);
			system("pause");
			break;
		case '0':
			printf("\nллʹ�ã��ټ���\n");
			break;
		default:
			printf("�������ѡ��Ϸ���������ѡ��\n");
		}
	}

	return 0;
}

void InitQueue(SeqQueue* Q)//��ʼ������ 
{
	Q->rear = 0;
	Q->front = 0;
	Q->count = 0;
}
int IsEmpty(SeqQueue* Q)//�п�
{
	if (Q->count != 0) return TRUE;//�ǿ�1����0
	else return FALSE;
}
int IsFull(SeqQueue* Q)//���� 
{
	if (Q->count > 0 && Q->rear == Q->front) return TRUE;//��1������0
	else return FALSE;
}
int EnterQueue(SeqQueue* Q, DataType x) //������
{
	//��x����ѭ������Q�Ķ�β���ɹ�1��ʧ��0
	if (IsFull(Q))
	{
		printf("���������޷����룡\n");
		return FALSE;
	}
	else//�������
	{
		Q->elem[Q->rear] = x;//��β����x
		Q->rear =(Q->rear+1)% MAXSIZE;//��βָ��+1
		Q->count++;//������+1
	    return TRUE;
	}
}
int DeleteQueue(SeqQueue* Q, DataType* x) //������
{
	//ɾ��˳��ѭ������Q�Ķ�ͷԪ�أ�������x���ɹ�1��ʧ��0
	if (IsFull(Q))
	{
		printf("�����ѿգ���Ԫ�س����У�\n");
		return 0;
	}
	else
	{
		*x = Q->elem[Q->front];//ɾ����ͷԪ��
		Q->front=(Q->front+1) % MAXSIZE;//��ͷָ��+1
		Q->count--;//������-1
		return TRUE;
	}
}

void PrintQueue(SeqQueue* Q)  //�Ӷ�ͷ��ӡ����β
{
	printf("�Ӷ�ͷ����βԪ��Ϊ��");
	for (int i = Q->front; i < Q->rear; i=(i+1)%MAXSIZE) 
	{	
		printf("%d ", Q->elem[i]);
	}
	printf("\n");
}
void PrintQueue1(SeqQueue* Q)  //�Ӷ�β��ӡ����ͷ
{
	printf("�Ӷ�β����ͷԪ��Ϊ��");

	for (int i = Q->rear-1; i != Q->front-1; i = (i - 1) % MAXSIZE)
	{
		printf("%d ", Q->elem[i]);
	}
}
