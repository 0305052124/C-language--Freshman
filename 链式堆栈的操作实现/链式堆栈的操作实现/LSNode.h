#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

typedef int DataType;

//������ʽ��ջ���Ľṹ�嶨�����£�
typedef struct snode
{
	DataType data;//���Ԫ�ص�������data
	struct snode* next;//���ָ����һ�����ָ���ָ����next
}LSNode;

void StackInitiate(LSNode** head);//��ʼ����ͷ�����ʽ��ջ
int StackNotEmpty(LSNode* head);//�ǿշ�
void StackPush(LSNode* head, DataType x);//��ջ
int StackPop(LSNode* head, DataType* d);//��ջ
void Destroy(LSNode* head);//������̬����ռ�
