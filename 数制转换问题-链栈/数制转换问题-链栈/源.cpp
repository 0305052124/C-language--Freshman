#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct snode
{
	datatype data;
	struct snode* next;
}LSNode, * linkstack;

int Push(linkstack* top, datatype x)/*入栈*/
{
	linkstack s = (linkstack)malloc(sizeof(struct snode));
	if (s == NULL)
		return 0;
	s->data = x;
	s->next = *top;  //把当前栈顶指针元素赋给插入结点的后继 
	*top = s;        //把新结点赋给栈顶指针 
	return 1;
}

int Empty(linkstack top)/*判空*/
{
	if (top == NULL)
		return 1;
	return 0;
}

int Pop(linkstack* top, datatype* x)/*出栈*/
{
	if (top != NULL)   //如果栈不为空则将元素出栈 
	{
		linkstack p = *top;
		*x = (*top)->data;
		*top = (*top)->next;  //栈顶指针下移一位 
		free(p);    //释放p结点 
		return 1;
	}
	return 0;
}

int main()
{
	int N, r;
	printf("输入要转化的和要转化进制：");
	scanf_s("%d%d", &N, &r);
	int h;
	linkstack top = NULL;
	if (N > 0)
	{
		printf("%d=(", N);
		while (N != 0)
		{
			h = N % r;
			Push(&top, h);
			N = N / r;
		}

		while (!Empty(top))
		{
			Pop(&top, &h);
			if (h == 10) printf("A");
			else if (h == 11) printf("B");
			else if (h == 12) printf("C");
			else if (h == 13) printf("D");
			else if (h == 14) printf("E");
			else if (h == 15) printf("F");
			else if (h < 10) printf("%d", h);
		}
	}
	else if (N < 0)
	{
		printf("%d=(-", N);
		N = -N;
		while (N != 0)
		{
			h = N % r;
			Push(&top, h);
			N = N / r;
		}
		while (!Empty(top))
		{
			Pop(&top, &h);
			if (h == 10) printf("A");
			else if (h == 11) printf("B");
			else if (h == 12) printf("C");
			else if (h == 13) printf("D");
			else if (h == 14) printf("E");
			else if (h == 15) printf("F");
			else if (h < 10) printf("%d", h);
		}
	}
	else
		printf("0=（0");
	printf(")%d", r);
}


