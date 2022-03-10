#define _CRT_SECURE_NO_WARNINGS 1
//双向循环链表
//初始化
#include<stdio.h>
#include<malloc.h>
typedef int Datatype;
typedef struct Node
{
	Datatype data;
	struct Node* next;
	struct Node* prior;
}SLNode;
void ListInitiata(SLNode** head)
{
	*head = (SLNode*)malloc(sizeof(SLNode));
	(*head)->next = *head;
	(*head)->prior = *head;
}
int ListInsert(SLNode* head, int i, Datatype x)
{
	SLNode* p = head->next;
	SLNode* s;
	int j;
	while (p != head && j < i)
	{
		p = p->next;
		j++;
	}
	if (j != i)
	{
		printf("插入元素位置参数错误！\n");
		return 0;
	}
	s = (SLNode*)malloc(sizeof(SLNode));
	s->data = x;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return 1;
}
int ListDelete(SLNode* head, int i, Datatype* x)
{
	SLNode* p = head->next;
	int j = 0;
	while (p->next != head && j < i)
	{
		p = p->next;
		j++;
	}
	if (j != i)
	{
		printf("插入元素位置参数错误！\n");
		return 0;
	}
	*x = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	free(p);
	return 1;
}
int ListLength(SLNode* head)
{
	int size = 0;
	SLNode* p = head;
	while (p->next != head)
	{
		p = p->next;
		size++;
	}
	return size;
}
void Destroy(SLNode** head)
{
	int n = ListLength(*head);
	int i = 0;
	SLNode* p1;
	SLNode* p = *head;
	for (i = 0; i < n; i++)
	{
		p1 = p;
	    p=p->next;
		free(p1);
	}
	*head = NULL;
}
int main()
{
	SLNode* head;
	Datatype x;
	ListInitiata(&head);
	int ret = ListInsert(head, 4, x);
	int sum = ListDelete(head, 4, &x);
	int size = ListLength(head);
	Destroy(&head);
	return 0;
}