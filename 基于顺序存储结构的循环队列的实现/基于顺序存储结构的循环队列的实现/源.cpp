#define _CRT_SECURE_NO_WARNINGS 1
//Queue On Sequence Structure
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE  100
#define FALSE   0
#define TRUE    1

typedef int DataType; //数据元素类型定义
DataType x;
typedef struct
{
	DataType elem[MAXSIZE];
	int  rear;
	int  front;
	int  count;
}SeqQueue;


void InitQueue(SeqQueue* Q);//初始化队列 
int IsEmpty(SeqQueue* Q);//判空 
int IsFull(SeqQueue* Q);//判满 
int EnterQueue(SeqQueue* Q, DataType x); //进队列 
int DeleteQueue(SeqQueue* Q, DataType* x); //出队列 
void PrintQueue(SeqQueue* Q);  //从队头打印到队尾
void PrintQueue1(SeqQueue* Q);  //从队尾打印到队头
 

int main()
{
	SeqQueue Q;  //创建一个队列Q 
	char sel = ' ';
	while (sel != '0')
	{
		printf("------队列(循环顺序存储结构)演示系统-------\n");
		printf("   版本:1.0   作者:金春依 日期:2022-04-14\n");
		printf("------------------------------------------\n");
		printf("       1.初始化队列\n");
		printf("       2.进队列操作\n");
		printf("       3.出队列操作\n");
		printf("       4.打印队列长度\n");
		printf("       5.打印队列(从队头到队尾)\n");
		printf("       6.清空屏幕\n");
		printf("       7.打印队列(从队尾到队头)\n");
		printf("       0.退出系统\n");
		printf("请输入选项[0-7]:");
		sel = getchar();
		switch (sel)
		{
		case '1':
			printf("初始化队列.\n");
			InitQueue(& Q);//初始化队列 
			system("pause");  
			break;
		case '2':
			printf("进队列操作.\n");
			printf("请输入要入队列的元素：");
			scanf_s("%d", &x);
			EnterQueue(&Q, x); //进队列 
			PrintQueue(&Q);//打印
			system("pause"); 
			break;
		case '3':
			printf("出队列操作.\n");
			DeleteQueue(&Q,&x);
			PrintQueue(&Q);//打印
			system("pause"); 
			break;
		case '4':
			printf("打印队列长度操作.\n");
			printf("队列长度为%d\n",Q.count);
			system("pause");  
			break;
		case '5':
			printf("打印队列操作(从队头到队尾部).\n");
			PrintQueue(&Q);
			system("pause"); 
			break;
		case '6':
			system("cls");
			break;
		case '7':
			printf("打印队列操作(从队尾到队头).\n");
			PrintQueue1(&Q);
			system("pause");
			break;
		case '0':
			printf("\n谢谢使用，再见！\n");
			break;
		default:
			printf("您输入的选项不合法，请重新选择！\n");
		}
	}

	return 0;
}

void InitQueue(SeqQueue* Q)//初始化队列 
{
	Q->rear = 0;
	Q->front = 0;
	Q->count = 0;
}
int IsEmpty(SeqQueue* Q)//判空
{
	if (Q->count != 0) return TRUE;//非空1，空0
	else return FALSE;
}
int IsFull(SeqQueue* Q)//判满 
{
	if (Q->count > 0 && Q->rear == Q->front) return TRUE;//满1，不满0
	else return FALSE;
}
int EnterQueue(SeqQueue* Q, DataType x) //进队列
{
	//把x插入循环队列Q的队尾，成功1，失败0
	if (IsFull(Q))
	{
		printf("队列已满无法插入！\n");
		return FALSE;
	}
	else//插入操作
	{
		Q->elem[Q->rear] = x;//队尾插入x
		Q->rear =(Q->rear+1)% MAXSIZE;//队尾指针+1
		Q->count++;//计数器+1
	    return TRUE;
	}
}
int DeleteQueue(SeqQueue* Q, DataType* x) //出队列
{
	//删除顺序循环队列Q的队头元素，并赋给x，成功1，失败0
	if (IsFull(Q))
	{
		printf("队列已空，无元素出队列！\n");
		return 0;
	}
	else
	{
		*x = Q->elem[Q->front];//删除队头元素
		Q->front=(Q->front+1) % MAXSIZE;//队头指针+1
		Q->count--;//计数器-1
		return TRUE;
	}
}

void PrintQueue(SeqQueue* Q)  //从队头打印到队尾
{
	printf("从队头到队尾元素为：");
	for (int i = Q->front; i < Q->rear; i=(i+1)%MAXSIZE) 
	{	
		printf("%d ", Q->elem[i]);
	}
	printf("\n");
}
void PrintQueue1(SeqQueue* Q)  //从队尾打印到队头
{
	printf("从队尾到队头元素为：");

	for (int i = Q->rear-1; i != Q->front-1; i = (i - 1) % MAXSIZE)
	{
		printf("%d ", Q->elem[i]);
	}
}
