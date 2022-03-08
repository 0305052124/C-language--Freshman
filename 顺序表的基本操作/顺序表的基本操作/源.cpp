#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define Maxsize  100
typedef int DataType;
typedef struct
{
	DataType  list[Maxsize];
	int size;
}SeqList;//定义结构体Seqlist
void ListInitiate(SeqList* L)//初始化 顺序表L
{
	L->size = 0;   //定义初始元素个数
}
int ListLength(SeqList L)
{
	return L.size;
}
int  ListInsert(SeqList* L, int i, DataType x)
{
	//在顺序表第i个位置前插入元素x
	//插入成功返回1，插入失败返回0
	int j;
	if (i<0 || i>L->size)
	{
		printf("参数i不合法 \n");
		return 0;
	}
	else if (L->size >= Maxsize)
	{
		printf("顺序表已满无法插入 \n");
		return 0;
	}
	else
	{
		for (j = L->size; j > i; j--)
		{
			L->list[j] = L->list[j - 1];//i和i后的数据往后移
		}
		L->list[i] = x;   //在顺序表第i个位置插入x
		L->size++;       //顺序表长度+1
		return 1;
	}
}
int ListDelete(SeqList* L, int i, DataType* x)
{
	int j;
	if (i<0 || i> L->size-1)
	{
		printf("参数i不合法 \n");
		return 0;
	}
	else if(L->size <=0)
	{
		printf("顺序表已空无法插入 \n");
		return 0;
	}
	else
	{
		*x = L->list[i];
		for (j = i + 1; j <= L->size - 1; j++)
		{
			L->list[j-1] = L->list[j];
		}
		L->size--;
		return 1;
	}
}
int ListGet(SeqList L, int i, DataType* x)
{
	if (i<0 || i>L.size - 1)
	{
		printf("参数i不合法 \n");
		return 0;
	}
	else
	{
		*x = L.list[i];
		return 1;
	}
}
int main()
{
	SeqList* L;
	ListInitiate(L);//1.初始化 顺序表L
	ListLength(*L);//2.求当前元素个数
	int i = 0;
	scanf_s("%d", &i);
	DataType x;


	ListInsert(L, i, x); //3.在顺序表中插入元素
	ListDelete(L, i, &x);//4.在顺序表中删除元素
	ListGet(*L, i, &x);  //5.在顺序表中取出元素

	return 0;
}