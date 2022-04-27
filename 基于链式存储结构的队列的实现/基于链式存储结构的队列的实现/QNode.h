#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<conio.h> 
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
	QNode* front,* rear;
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
//int QueueGet(LQueue Q, datatype* x);//取队头元素