#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define MaxStackSize 10// MaxStackSize��ʾ˳���ջ����Stack������ڴ浥Ԫ����������洢��Ԫ����������
typedef int DataType;

//����ṹ��SeqStack������������飬��ջ��λ��
typedef struct {
	DataType Stack[MaxStackSize];//Stack��ʾ˳���ջ���Ԫ�ص�����
	int top;//top��ʾ˳���ջ����Stack�ĵ�ǰջ��λ��
}SeqStack;

//DataType d, x;
//SeqStack S;

void StackInitiate(SeqStack* S);//��ʼ��˳���ջS
int StackNotEmpty(SeqStack S);//�ǿշ�
int StackPush(SeqStack* S, DataType x);//��ջ
int StackPop(SeqStack* S, DataType* d);//��ջ
int StackTop(SeqStack S, DataType* d);//ȡջ��Ԫ��