#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define MaxQueueSize 10
typedef int DataType;

//结构体定义
typedef struct {
	DataType queue[MaxQueueSize];
	int rear;//队尾指针
	int front;//队头指针
	int count;//计数器
}SeqCQueue;

void QueueInitiate(SeqCQueue* Q);//初始化
int  QueueNotEmpty(SeqCQueue  Q);//非空否
int QueueAppend  (SeqCQueue* Q, DataType x);//入队列
int QueueDelete(SeqCQueue* Q, DataType * d);//出队列
int QueueGet(SeqCQueue Q, DataType * d);//取队头元素
