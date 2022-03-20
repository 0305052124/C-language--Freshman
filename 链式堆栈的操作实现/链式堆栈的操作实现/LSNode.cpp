#define _CRT_SECURE_NO_WARNINGS 1
#include"LSNode.h"
void StackInitiate(LSNode** head)//初始化带头结点链式堆栈
{
	//初始化带头结点链式堆栈
	*head = (LSNode*)malloc(sizeof(LSNode));
	(*head)->next = NULL;
}


int StackNotEmpty(LSNode* head)//非空否
{
	//判断堆栈是否非空，非空：return 1，空：return 0
	if (head->next == NULL)  return 0;
	else return 1;
}

void StackPush(LSNode* head, DataType x)//入栈
{
	//把元素x插入链式堆栈head的栈顶作为新的栈顶
	LSNode* p;
	p= (LSNode*)malloc(sizeof(LSNode));
	p->data = x;
	p->next = head->next;//新结点链入栈顶
	head->next = p;//新结点成为新的栈顶
}

int StackPop(LSNode* head, DataType* d)//出栈
{
	//出栈并把栈顶元素由元素d带回，若出栈成功return 1，失败return 0；
	LSNode* p=head->next;
	if (p == NULL)
	{
		printf("堆栈已空出错！\n");
	    return 0;
	}
	else
	{
		head->next = p->next;
		*d = p->data;
		free(p);
		return 1;
	}
}


void Destroy(LSNode* head)//撤销动态申请空间
{
	LSNode* p, * p1;
	p = head;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}