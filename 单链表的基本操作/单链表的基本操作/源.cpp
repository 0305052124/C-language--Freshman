#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
typedef int Datatype;
typedef struct Node//单链表的节点定义
{
	Datatype data;
	struct Node*  next;
}SLNode;
void ListInitiata(SLNode** head)//初始化单链表
{
	*head = (SLNode*)malloc(sizeof(SLNode));//申请头结点，由head指示其地址
	(*head)->next = NULL;  //置结束标志NULL
}
int ListLength(SLNode** head)//求当前元素个数
{
	SLNode* p = *head;    //p指针指向头结点
	int size = 0;             
	while (p->next != NULL)
	{
		p = p->next;        //p指向下个地址
		size++;
	}
	return size;
}
int ListInsert(SLNode* head, int  i, Datatype x)
{
	//在带头结点的单链表head的第i（0~size）个结点前插入一个元素x的结点
	//插入成功返回1，失败返回0
	SLNode * p=head;
	SLNode* q;
	int j =-1;
	while (p->next != NULL && j < i - 1)//保证指针所指结点存在，保证最终让指针p指向i-1结点
	{
		//让指针p指向第i-1个结点
		p=p->next;
		j++;
	}
	if (j != i - 1)
	{
		printf("插入元素位置参数错误\n");
		return 0;
	}
	q = (SLNode*)malloc(sizeof(SLNode));//生成新结点
	q->data = x;//给新结点赋值

	q->next = p->next;
	p->next = q;
	
	return 1;
}
int ListDelete(SLNode* head, int  i, Datatype x)
{
	//删除带头结点单链表head的第i（0~size-1）个结点
	//被删除结点的数据由x带回，删除成功返回1，失败返回0
	SLNode* p = head;
	SLNode* q;
	int j=-1;
	while (p->next != NULL && j < i - 1 && p->next ->next!= NULL)
	{
		//p->next != NULL保证第i-1个结点存在
		//p->next ->next!= NULL保证第i个结点存在
		//j < i - 1保证循环结束指针p指向第i-1个结点
		//这样p->next就指向第i个指针了，也就是说，（q=p->next）q指针指向的结点就是第i个指针要删除的
		p=p->next;
		j++;
	}
	if (j != i - 1)
	{
		printf("插入元素位置参数错误\n");
		return 0;
	}
	q = p->next;//指针q指向第i个结点
	x = q->data;//把指针q指向结点里的数据放在x里带回
	p->next = p->next->next;//删除q指向的第i个结点,使第i个结点脱链
	free(q);//释放指针q所指结点的内存空间
	return 1;
}
int ListGet(SLNode* head, int  i, Datatype x)
{
	SLNode* p = head;
	int j = -1;
	while (p->next != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	if (j != i)
	{
		printf("插入元素位置参数错误\n");
		return 0;
	}
	x = p->data;
	return 1;
}
void Destroy(SLNode** head)
{
	SLNode* p = *head;
	while (p != NULL)
	{
		SLNode* p1 = p;
		p = p->next;
		free(p1);
	}
	*head = NULL;
}
int main()
{
	SLNode* head;     //定义头指针变量
	ListInitiata(&head);//传头指针地址
	int length =ListLength(& head);
	int i = 2;
	Datatype x;
	int y=ListInsert( head, i, x);//插入函数
	int m = ListDelete(head, i, x);//删除函数
	int n = ListGet(head, i, x);//取元素函数
	Destroy(&head);//撤销单链表
	return 0;
}