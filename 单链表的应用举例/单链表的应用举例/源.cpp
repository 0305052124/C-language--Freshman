#define _CRT_SECURE_NO_WARNINGS 1
//建立一个线性表，首次输入元素1，2，3~10，然后删除元素5，最后依次显示当前表中的元素
#include<stdio.h>
#include<malloc.h>
typedef int Datatype;
typedef struct Node
{
	Datatype data;
	struct Node* next;
}SLNode;
void ListInitiata(SLNode** head)
{
	*head = (SLNode*)malloc(sizeof(SLNode));
	(*head)->next = NULL;
}
void ListInsert(SLNode* head, int i )
{
	SLNode* p = head;
	SLNode* q;
	int j = -1;
	q = (SLNode*)malloc(sizeof(SLNode));
	q->data = i + 1;
	q->next = p->next;
	p->next = q;
}
void ListDelete(SLNode* head, int i, Datatype* x)
{
	SLNode* p = head;
	SLNode* q;
	int j = -1;
	while (p->next != NULL && p->next->next != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	q = p->next;
	*x = q->data;
	p->next = p->next->next;
	free(q);
}
int ListLength(SLNode* head)
{
	int size = 0;
	SLNode* p = head;
	while (p->next != NULL)
	{
		p = p->next;
		size++;
	}
	return size;
}
void ListGet(SLNode* head, int  i, Datatype* x)
{
	int j = -1;
	SLNode* p = head;
	while (p->next != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (j != i)
	{
		printf("取元素位置参数错误\n");
		return ;
	}
	*x = p->data;
	return ;
}
void Destroy(SLNode** head)
{
	SLNode* p = *head;
	SLNode* q;
	while (p  != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
	*head = NULL;
}
int main()
{
	SLNode* head;
	int i, x;	
	ListInitiata(&head);
	for (i = 0; i < 10; i++)
	{
		ListInsert(head, i);
	}
	ListDelete(head, 5, &x);
	for (i =0; i <ListLength(head); i++)
	{
		ListGet(head, i, &x);
		printf("%d  ", x);
	}
	Destroy(&head);
	return 0;
}