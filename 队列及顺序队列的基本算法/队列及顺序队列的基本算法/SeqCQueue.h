#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define MaxQueueSize 10
typedef int DataType;

//�ṹ�嶨��
typedef struct {
	DataType queue[MaxQueueSize];
	int rear;//��βָ��
	int front;//��ͷָ��
	int count;//������
}SeqCQueue;

void QueueInitiate(SeqCQueue* Q);//��ʼ��
int  QueueNotEmpty(SeqCQueue  Q);//�ǿշ�
int QueueAppend  (SeqCQueue* Q, DataType x);//�����
int QueueDelete(SeqCQueue* Q, DataType * d);//������
int QueueGet(SeqCQueue Q, DataType * d);//ȡ��ͷԪ��
