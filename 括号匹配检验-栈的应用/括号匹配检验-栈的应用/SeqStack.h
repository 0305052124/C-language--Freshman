#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <iostream>
#include <cstring>//必须是cstring，否则strlen()方法不能用
#include<math.h>
#define TRUE 1
#define FALSE 0
#define MaxSize 100
typedef struct {
	char data[MaxSize];
	int top;
}SeqStack;
typedef char DataType;
void  InitStack(SeqStack* S);//初始化栈 
int GetTop(SeqStack S, DataType* x);
int Push(SeqStack* S, DataType x); //进栈
int Pop(SeqStack* S, DataType* x);//出栈
int IsEmpty(SeqStack* S);