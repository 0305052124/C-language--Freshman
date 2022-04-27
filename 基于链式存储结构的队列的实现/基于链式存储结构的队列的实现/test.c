#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

typedef int datatype;

//队列元素节点类型 ,结构体定义命名为QNode
typedef struct node {
	datatype data;
	struct node* next;
}QNode;

//队节点类型, 定义队头队尾指针
typedef struct {
	QNode* front, * rear;
}LQueue;

int Init_LQueue(LQueue* Q);
//链队列Q进行初始化(创建头节点),初始化成功则返回TRUE,否则返回FALSE
int EnLQueue(LQueue* Q, datatype x);
//把元素x入队列Q,成功则返回TURE,否则返回FALSE 
int DeleteLQueue(LQueue* Q, datatype* x);
//把元素*x入队列Q,成功则返回TRUE,否则返回FALSE 
int IsEmpty(LQueue* Q);//判空 
void PrintLQueue(LQueue* Q);  //从队头打印到队尾
int  LengthLQueue(LQueue* Q); //计算队列长度 
void DestroyLQueue(LQueue* Q);  //销毁队列 

int main()
{
	LQueue Q;  //创建一个队列Q 
	int i = -1;
	int num = 0;
	int ret = 0;
	char sel = ' ';
	while (sel != '0')
	{

		printf("------队列(链式存储结构)演示系统-------\n");
		printf("   版本:1.0   作者:金春依 日期:2022-04-27\n");
		printf("------------------------------------------\n");
		printf("       1.初始化队列\n");
		printf("       2.进队列操作\n");
		printf("       3.出队列操作\n");
		printf("       4.打印队列长度\n");
		printf("       5.打印队列(从队头到队尾）\n");
		printf("       6.清空屏幕\n");
		printf("       7.销毁队列\n");
		printf("       0.退出系统\n");
		printf("请输入选项[0-7]:");
		sel = getchar();
		switch (sel)
		{
		case '1':
			printf("初始化队列.\n");
			Init_LQueue(&Q);
			system("pause");
			break;
		case '2':
			printf("进队列操作.\n");
			printf("你要入几个元素：\n");
			scanf_s("%d", &i);
			printf("请输入%d个元素的值\n", i);
			for (int j = 0; j < i; j++)
			{
				scanf_s("%d", &num);
				EnLQueue(&Q, num);
			}
			PrintLQueue(&Q);
			system("pause");
			break;
		case '3':
			printf("出队列操作.\n");
			if (DeleteLQueue(&Q, &ret))
			{
				printf("出队成功\n");
				printf("出队元素为：%d\n", ret);
			}
			else printf("出队失败\n");
			PrintLQueue(&Q);
			system("pause");
			break;
		case '4':
			printf("打印队列长度操作.\n");
			printf("队列长度为：%d\n", LengthLQueue(&Q));//打印队列长度 
			PrintLQueue(&Q);
			system("pause");
			break;
		case '5':
			printf("打印队列操作(从队头到队尾部).\n");
			PrintLQueue(&Q);  //从队头打印到队尾
			system("pause");
			break;
		case '6':
			system("cls");
			break;
		case '7':
			printf("销毁队列.\n");
			DestroyLQueue(&Q);  //销毁队列 
			PrintLQueue(&Q);
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
int Init_LQueue(LQueue* Q)//对队列Q进行初始化(创建头节点),初始化成功则返回TRUE,否则返回FALSE
{
	Q->front = NULL;//定义初始队头指针下标值
	Q->rear = NULL;//定义初始队尾指针下标值
	return TRUE;

}
int  LengthLQueue(LQueue* Q)//计算队列长度 
{
	QNode* p;
	int count = 0;
	p = Q->front;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}
void PrintLQueue(LQueue* Q)
//从队头到队尾打印队列Q 
{
	printf("目前队列(从队头到队尾部)为：");
	QNode* p;
	p = Q->front; //指向队列的第1个节点 
	printf("(");
	while (p != NULL && p->next != NULL) //不是最后1个节点 
	{
		printf("%d,", p->data);
		p = p->next;
	}
	if (p != NULL)  //打印最后1个节点 
		printf("%d", p->data);
	printf(")\n");
}

int DeleteLQueue(LQueue* Q, datatype* x)//把元素*x出队列Q,成功则返回TRUE,否则返回FALSE 
{
	//删除链式队列Q的队头元素，并赋给x
	QNode* p;
	if (Q->front == NULL)//对空判断
	{
		printf("队列已空，无元素出队列！ \n");
		return FALSE;
	}
	else
	{
		*x = Q->front->data;
		p = Q->front;
		Q->front = Q->front->next;//出队列结点脱链
		if (Q->front == NULL)//删除最后一个结点时，要置队尾指针为空
		{
			Q->rear = NULL;
		}
		free(p);
		return TRUE;
	}
}

void DestroyLQueue(LQueue* Q)//销毁队列 撤销动态申请空间
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}
int  IsEmpty(LQueue* Q)//非空否
{
	//判断链式队列Q非空否，非空return 1，否则return 0
	if (Q->front == NULL)
	{
		return FALSE;
	}
	else return TRUE;
}

int EnLQueue(LQueue* Q, datatype x)//把元素x入队列Q,成功则返回TURE,否则返回FALSE 
{
	//把x插入链式队列Q的队尾
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;
	if (Q->rear != NULL) Q->rear->next = p;//队列原来非空时队尾加新结点
	Q->rear = p;//修改队尾指针
	if (Q->front == NULL) Q->front = p;//队列原来为空时修改队头指针
	return TRUE;
}
