#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct snode
{
	datatype data;
	struct snode* next;
}LSNode, * linkstack;

int Push(linkstack* top, datatype x)/*��ջ*/
{
	linkstack s = (linkstack)malloc(sizeof(struct snode));
	if (s == NULL)
		return 0;
	s->data = x;
	s->next = *top;  //�ѵ�ǰջ��ָ��Ԫ�ظ���������ĺ�� 
	*top = s;        //���½�㸳��ջ��ָ�� 
	return 1;
}

int Empty(linkstack top)/*�п�*/
{
	if (top == NULL)
		return 1;
	return 0;
}

int Pop(linkstack* top, datatype* x)/*��ջ*/
{
	if (top != NULL)   //���ջ��Ϊ����Ԫ�س�ջ 
	{
		linkstack p = *top;
		*x = (*top)->data;
		*top = (*top)->next;  //ջ��ָ������һλ 
		free(p);    //�ͷ�p��� 
		return 1;
	}
	return 0;
}

int main()
{
	int N, r;
	printf("����Ҫת���ĺ�Ҫת�����ƣ�");
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
		printf("0=��0");
	printf(")%d", r);
}


