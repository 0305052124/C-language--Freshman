#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

typedef int DataType;


//结构体定义命名为LQNode
typedef struct qnode {
	DataType data;
	struct qnode* next;
}LQNode;

//定义队头队尾指针
typedef struct {
	LQNode* front;
	LQNode* rear;
}LQueue;

void QueueInitiate(LQueue* Q);//初始化链式队列Q
int  QueueNotEmpty(LQueue  Q);//非空否
void  QueueAppend(LQueue* Q, DataType x);//入队列
int QueueDelete(LQueue* Q, DataType* d);//出队列
int QueueGet(LQueue Q, DataType* d);//取队头元素
void Destroy(LQueue Q);//撤销动态申请空间