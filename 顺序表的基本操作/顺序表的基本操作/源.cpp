#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define Maxsize  100
typedef int DataType;
typedef struct
{
	DataType  list[Maxsize];
	int size;
}SeqList;//����ṹ��Seqlist
void ListInitiate(SeqList* L)//��ʼ�� ˳���L
{
	L->size = 0;   //�����ʼԪ�ظ���
}
int ListLength(SeqList L)
{
	return L.size;
}
int  ListInsert(SeqList* L, int i, DataType x)
{
	//��˳����i��λ��ǰ����Ԫ��x
	//����ɹ�����1������ʧ�ܷ���0
	int j;
	if (i<0 || i>L->size)
	{
		printf("����i���Ϸ� \n");
		return 0;
	}
	else if (L->size >= Maxsize)
	{
		printf("˳��������޷����� \n");
		return 0;
	}
	else
	{
		for (j = L->size; j > i; j--)
		{
			L->list[j] = L->list[j - 1];//i��i�������������
		}
		L->list[i] = x;   //��˳����i��λ�ò���x
		L->size++;       //˳�����+1
		return 1;
	}
}
int ListDelete(SeqList* L, int i, DataType* x)
{
	int j;
	if (i<0 || i> L->size-1)
	{
		printf("����i���Ϸ� \n");
		return 0;
	}
	else if(L->size <=0)
	{
		printf("˳����ѿ��޷����� \n");
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
		printf("����i���Ϸ� \n");
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
	ListInitiate(L);//1.��ʼ�� ˳���L
	ListLength(*L);//2.��ǰԪ�ظ���
	int i = 0;
	scanf_s("%d", &i);
	DataType x;


	ListInsert(L, i, x); //3.��˳����в���Ԫ��
	ListDelete(L, i, &x);//4.��˳�����ɾ��Ԫ��
	ListGet(*L, i, &x);  //5.��˳�����ȡ��Ԫ��

	return 0;
}