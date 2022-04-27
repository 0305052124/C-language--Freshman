#define _CRT_SECURE_NO_WARNINGS 1
#include"QNode.h"
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
	QNode* p;
	p = Q->front->next; //指向队列的第1个节点 
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
//int QueueGet(LQueue Q, datatype* x)//取队头元素
//{
//	//取链式队列Q的当前队头元素，并赋给x，
//	//成功return 1，失败return 0
//	//对空判断
//	if (Q.front == NULL)
//	{
//		printf("队列已空，无元素可取！ \n");
//		return 0;
//	}
//	else
//	{
//		*x = Q.front->data;
//		return 1;
//	}
//}
int DeleteLQueue(LQueue* Q, datatype* x)//把元素*x出队列Q,成功则返回TRUE,否则返回FALSE 
{
	//删除链式队列Q的队头元素，并赋给x
	QNode* p;
	if (Q->front == NULL)//对空判断
	{
		printf("队列已空，无元素出队列！ \n");
		return 0;
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
		return 1;
	}
}

void DestroyLQueue(LQueue*  Q)//销毁队列 撤销动态申请空间
{
	QNode* p, * p1;
	p = Q->front;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}
int  IsEmpty(LQueue*Q)//非空否
{
	//判断链式队列Q非空否，非空return 1，否则return 0
	if (Q->front == NULL)
	{
		return FALSE;
	}
	else return TRUE;
}
int Init_LQueue(LQueue* Q)//对队列Q进行初始化(创建头节点),初始化成功则返回TRUE,否则返回FALSE
{
	Q->front = NULL;//定义初始队头指针下标值
	Q->rear = NULL;//定义初始队尾指针下标值
	return TRUE;
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








