#define _CRT_SECURE_NO_WARNINGS 1
//1����дһ���㷨���������������е�����Ԫ�ء���Ԫ�ص���������Ϊint����.
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
//	printf("������");
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
//	Node*  x= &node;        //������ָ��
//    listInitiate(&x);       //��ʼ��������
//    int a[18] = { 1,5,22,45,12,16,36,59,48,32,15,33,222,15,64,77,48,32 };
//    listBuildRear(x, a, 10); //Ϊ��������10������ȥ
//    listPrint(x);           //��������������е�����
//	return 0;
//}
//2����дһ���㷨��������˳����е�����Ԫ�ء���Ԫ�ص���������Ϊint���͡�



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LONG 5         //�����޸�˳���ĳ���
#define MAXSIZE 50
typedef int DataType;  //����Ԫ������Ϊint
typedef struct
{
	DataType a[MAXSIZE]; //���洢��Ԫ����
	int size;            //��ǰ�洢��Ԫ����
} Seqlist;             //����ṹ��seqlist����

void listinitiate(Seqlist* L)//��ʼ��˳���L
{
	int i;
	L->size = 0;//�����ʼ����Ԫ�ظ���Ϊ0;
	for (i = 0; i < LONG; i++)
	{
		L->size ++;
	}
}

void printlist(Seqlist* L)
{
	int i;
	srand(time(NULL));//ʹ�������������˳���Ԫ��
	printf("˳����е�Ԫ��Ϊ: ");
	for (i = 0; i < L->size; i++)
	{
		printf("%d ", rand() % 10);//���ֵ
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
