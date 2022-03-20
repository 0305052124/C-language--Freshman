#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqCQueue.h"


void QueueInitiate(SeqCQueue* Q)//初始化顺序循环队列Q
{
	Q->rear = 0;//定义初始队尾指针下标值
	Q->front = 0;//定义初始队头指针下标值
	Q->count = 0;//定义初始计数器值
}


int  QueueNotEmpty(SeqCQueue  Q)//非空否
{
	//判断顺序循环队列Q非空否，非空return 1，否则return 0
	if (Q.count != 0) return 1;
	else return 0;
}


int QueueAppend(SeqCQueue* Q, DataType x)//入队列
{
	//把x插入顺序循环队列Q的队尾，成功返回1，失败返回0
	//队满判断：首尾相等，count>0
	if (Q->count > 0 && Q->rear == Q->front)
	{
		printf("队列已满无法插入！ \n");
		return 0;
	}
	else
	{
		Q->queue[Q->rear] = x; //元素x插入队尾
		Q->rear = (Q->rear + 1) % MaxQueueSize;//队尾指针加1
		Q->count++;//计数器加1
	}
}


int QueueDelete(SeqCQueue* Q, DataType* d)//出队列
{
	//删除顺序循环队列Q的队头元素，并赋给d
	//成功return 1，失败return 0
	//对空判断
	if (Q->count <= 0)
	{
		printf("队列已空，无元素出队列！ \n");
		return 0;
	}
	else
	{
		*d=Q->queue[Q->front];//取队头元素存入d中
		Q->front = (Q->front + 1) % MaxQueueSize;//队头指针加1
		Q->count--;//计数器减1
		return 1;
	}
}


int QueueGet(SeqCQueue Q, DataType* d)//取队头元素
{
	//取顺序循环队列Q的当前队头元素，并赋给b，
	//成功return 1，失败return 0
	//对空判断
	if (Q.count <= 0)
	{
		printf("队列已空，无元素可取！ \n");
		return 0;
	}
	else
	{
		*d = Q.queue[Q.front];
		return 1;
 }
}