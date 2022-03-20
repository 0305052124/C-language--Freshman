#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

typedef int DataType;

//定义链式堆栈结点的结构体定义如下：
typedef struct snode
{
	DataType data;//存放元素的数据域data
	struct snode* next;//存放指向下一个结点指针的指针域next
}LSNode;

void StackInitiate(LSNode** head);//初始化带头结点链式堆栈
int StackNotEmpty(LSNode* head);//非空否
void StackPush(LSNode* head, DataType x);//入栈
int StackPop(LSNode* head, DataType* d);//出栈
void Destroy(LSNode* head);//撤销动态申请空间
