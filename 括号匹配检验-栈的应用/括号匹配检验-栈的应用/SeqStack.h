#define _CRT_SECURE_NO_WARNINGS 1
#include<string.h>
#include<stdio.h>
#define TRUE 1
#define FALSE 0
#define MaxSize 100
typedef struct {
	char data[MaxSize];
	int top;
}SeqStack;
typedef char DataType;
void  InitStack(SeqStack* S);//��ʼ��ջ 
int GetTop(SeqStack S, DataType* x);
int Push(SeqStack* S, DataType x); //��ջ
int Pop(SeqStack* S, DataType* x);//��ջ
int IsEmpty(SeqStack* S);