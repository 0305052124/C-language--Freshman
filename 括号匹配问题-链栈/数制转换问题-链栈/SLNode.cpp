#define _CRT_SECURE_NO_WARNINGS 1
#include"SLNode.h"
LinkStack CreateLinkStack()  //创建一个空的链栈并返回 
{
	LinkStack top = (LinkStack)malloc(sizeof(LSNode));
	if (top == NULL)
	{
		printf("内存分配失败");
	}
	top->next = NULL;
	return top;
}
void PrintStack(LinkStack top) //打印栈元素(从栈顶到栈底顺序) 
{
	LinkStack p = top->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int GetTop(LinkStack top, char* x) //取栈顶元素，不出栈 
{
	LinkStack p = top->next;
	if (p == NULL)
	{
		printf("堆栈已空出错！");
		return FALSE;
	}
	*x = p->data;
	return TRUE;
}

void DestroyStack(LinkStack top)//释放栈的所有空间,包括头节点 
{
	LinkStack p, p1;
	p = top;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}
int IsEmpty(LinkStack top)//判空 
{
	//判断堆栈是否非空，非空：return TRUE，空：return FALSE
	if (top->next == NULL)
		return FALSE;
	else
		return TRUE;
}
void Push(LinkStack top, char x) //进栈 
{
	//把元素x插入链式堆栈head的栈顶作为新的栈顶

	LinkStack p;
	p = (LinkStack)malloc(sizeof(LSNode));
	p->data = x;
	p->next = top->next;//新结点链入栈顶
	top->next = p;//新结点成为新的栈顶
}
int Pop(LinkStack top, DataType* x)//出栈 
{
	//出栈并把栈顶元素由元素x带回，若出栈成功return 1，失败return 0；
	LinkStack p = top->next;
	if (p == NULL)
	{
		printf("堆栈已空出错！\n");
		return FALSE;
	}
	else
	{
		top->next = p->next;
		*x = p->data;
		free(p);
		return TRUE;
	}
}