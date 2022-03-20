#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

typedef int DataType;


//�ṹ�嶨������ΪLQNode
typedef struct qnode {
	DataType data;
	struct qnode* next;
}LQNode;

//�����ͷ��βָ��
typedef struct {
	LQNode* front;
	LQNode* rear;
}LQueue;

void QueueInitiate(LQueue* Q);//��ʼ����ʽ����Q
int  QueueNotEmpty(LQueue  Q);//�ǿշ�
void  QueueAppend(LQueue* Q, DataType x);//�����
int QueueDelete(LQueue* Q, DataType* d);//������
int QueueGet(LQueue Q, DataType* d);//ȡ��ͷԪ��
void Destroy(LQueue Q);//������̬����ռ�