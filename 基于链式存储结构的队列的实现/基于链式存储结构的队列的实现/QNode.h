#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<conio.h> 
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
typedef int datatype;

//����Ԫ�ؽڵ����� ,�ṹ�嶨������ΪQNode
typedef struct node {
	datatype data;
	struct node* next;
}QNode;

//�ӽڵ�����, �����ͷ��βָ��
typedef struct {
	QNode* front,* rear;
}LQueue;

int Init_LQueue(LQueue* Q);
//������Q���г�ʼ��(����ͷ�ڵ�),��ʼ���ɹ��򷵻�TRUE,���򷵻�FALSE
int EnLQueue(LQueue* Q, datatype x);
//��Ԫ��x�����Q,�ɹ��򷵻�TURE,���򷵻�FALSE 
int DeleteLQueue(LQueue* Q, datatype* x);
//��Ԫ��*x�����Q,�ɹ��򷵻�TRUE,���򷵻�FALSE 
int IsEmpty(LQueue* Q);//�п� 
void PrintLQueue(LQueue* Q);  //�Ӷ�ͷ��ӡ����β
int  LengthLQueue(LQueue* Q); //������г��� 
void DestroyLQueue(LQueue* Q);  //���ٶ��� 
//int QueueGet(LQueue Q, datatype* x);//ȡ��ͷԪ��