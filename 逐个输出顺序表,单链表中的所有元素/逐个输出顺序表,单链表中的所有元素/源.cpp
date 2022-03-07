#define _CRT_SECURE_NO_WARNINGS 1
//1、编写一个算法，逐个输出单链表中的所有元素。设元素的数据类型为int类型.
//#include<stdio.h>
//#include<stdlib.h>
//typedef int Datatype;
//typedef struct node
//{
//	Datatype data;
//	struct node* next;
//}Node;
//void listInitiate(Node*  *head)
//{
//    *head = (Node*)malloc(sizeof(node));
//	(*head)->next = NULL;
//}
//void listBuildRear(Node* head, Datatype a[], int n)
//{
//	Node* x=head;
//	for (int i = 0; i < n; i++)
//	{
//		Node* q = (Node*)malloc(sizeof(node));
//		q->data = a[i];
//		q->next =NULL;
//		x->next = q;
//			x = q;
//	}
//}
//void listPrint(Node* head)
//{
//	printf("单链表：");
//	Node* x = head;
//	while (x->next != NULL)
//	{
//		printf("%d  ", x->next->data);
//		x = x->next;
//	}
//}
//int main()
//{
//	Node node;
//	Node*  x= &node;        //单链表指针
//    listInitiate(&x);       //初始化单链表
//    int a[18] = { 1,5,22,45,12,16,36,59,48,32,15,33,222,15,64,77,48,32 };
//    listBuildRear(x, a, 10); //为单链表安排10个数进去
//    listPrint(x);           //遍历输出单链表中的数据
//	return 0;
//}
//2、编写一个算法，逐个输出顺序表中的所有元素。设元素的数据类型为int类型。



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LONG 5         //可以修改顺序表的长度
#define MAXSIZE 50
typedef int DataType;  //定义元素类型为int
typedef struct
{
	DataType a[MAXSIZE]; //最大存储单元个数
	int size;            //当前存储单元个数
} Seqlist;             //定义结构体seqlist结束

void listinitiate(Seqlist* L)//初始化顺序表L
{
	int i;
	L->size = 0;//定义初始数据元素个数为0;
	for (i = 0; i < LONG; i++)
	{
		L->size ++;
	}
}

void printlist(Seqlist* L)
{
	int i;
	srand(time(NULL));//使用随机函数生成顺序表元素
	printf("顺序表中的元素为: ");
	for (i = 0; i < L->size; i++)
	{
		printf("%d ", rand() % 10);//输出值
	}
	printf("\n");
}
int main()
{
	Seqlist aa;
	listinitiate(&aa);
	printlist(&aa);
	return 0;
}
