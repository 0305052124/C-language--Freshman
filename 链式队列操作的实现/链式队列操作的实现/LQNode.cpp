#define _CRT_SECURE_NO_WARNINGS 1

#include"LQNode.h"
void QueueInitiate(LQueue* Q)//初始化链式队列Q
{
	Q->front == NULL;//定义初始队头指针下标值
	Q->rear == NULL;//定义初始队尾指针下标值
}
int  QueueNotEmpty(LQueue  Q)//非空否
{
	//判断链式队列Q非空否，非空return 1，否则return 0
	if (Q.front == NULL)
	{
		return 0;
	}
	else return 1;
}
void  QueueAppend(LQueue* Q, DataType x)//入队列
{
	//把x插入链式队列Q的队尾
	LQNode* p;
	p = (LQNode*)malloc(sizeof(LQNode));
	p->data = x;
	p->next = NULL;
	if (Q->rear != NULL) Q->rear->next = p;//队列原来非空时队尾加新结点
	Q->rear = p;//修改队尾指针
	if (Q->front == NULL) Q->front = p;//队列原来为空时修改队头指针
}
int QueueDelete(LQueue* Q, DataType* d)//出队列
{
	//删除链式队列Q的队头元素，并赋给d
//成功return 1，失败return 0
//对空判断
	LQNode* p;
	if (Q->front == NULL)
	{
		printf("队列已空，无元素出队列！ \n");
		return 0;
	}
	else
	{
		*d = Q->front->data;
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
int QueueGet(LQueue Q, DataType* d)//取队头元素
{
	//取链式队列Q的当前队头元素，并赋给b，
	//成功return 1，失败return 0
	//对空判断
	if (Q.front ==NULL)
	{
		printf("队列已空，无元素可取！ \n");
		return 0;
	}
	else
	{
		*d = Q.front->data;
		return 1;
	}
}
void Destroy(LQueue Q)//撤销动态申请空间
{
	LQNode* p, * p1;
	p =Q.front;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}






