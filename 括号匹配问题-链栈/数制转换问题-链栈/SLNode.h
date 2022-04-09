#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MaxSize 100
#define FALSE   0  //失败 
#define TRUE    1  //成功 

typedef int DataType; //数据元素类型定义

typedef struct node
{
	DataType  data;
	struct node* next;
}LSNode, * LinkStack;

LinkStack CreateLinkStack();  //创建一个空的链栈并返回 
void  DestroyStack(LinkStack top);//释放栈的所有空间,包括头节点 
int IsEmpty(LinkStack top);//判空 
void Push(LinkStack top, char x); //进栈 
int Pop(LinkStack top, DataType* x); //出栈 
int GetTop(LinkStack top, char* x); //去栈顶元素 
void PrintStack(LinkStack top); //打印栈元素(从栈顶到栈底顺序) 