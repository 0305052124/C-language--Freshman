#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define MaxSize 100
#define FALSE   0  //ʧ�� 
#define TRUE    1  //�ɹ� 

typedef int DataType; //����Ԫ�����Ͷ���

typedef struct node
{
	DataType  data;
	struct node* next;
}LSNode, * LinkStack;

LinkStack CreateLinkStack();  //����һ���յ���ջ������ 
void  DestroyStack(LinkStack top);//�ͷ�ջ�����пռ�,����ͷ�ڵ� 
int IsEmpty(LinkStack top);//�п� 
void Push(LinkStack top, char x); //��ջ 
int Pop(LinkStack top, DataType* x); //��ջ 
int GetTop(LinkStack top, char* x); //ȥջ��Ԫ�� 
void PrintStack(LinkStack top); //��ӡջԪ��(��ջ����ջ��˳��) 