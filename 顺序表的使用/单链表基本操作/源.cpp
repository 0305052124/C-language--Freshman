#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define Maxsize 100
typedef int Datatype;
typedef struct
{
	Datatype list[Maxsize];
	int size;
}Seqlist;
void ListInitiate(Seqlist* mylist)
{
	mylist->size = 0;
};
void ListInsert(Seqlist* mylist, int  i, Datatype x )
{
	int j;
	for (j = mylist->size-1; j > i+1; j--)
	{
		mylist->list[j] = mylist->list[j - 1];
	}
	mylist->list[i] = x;
	mylist->size++;
}
void Listdelete(Seqlist* mylist, int  i, Datatype* x)
{
	int j;
	*x = mylist->list[i];
	for (j = i + 1; j < mylist->size ; j++)
	{
		mylist->list[j - 1] = mylist->list[j];
	}
	mylist->size--;

}
int Listlength(Seqlist mylist)
{
	return mylist.size;
}
void Listget(Seqlist mylist, int i, Datatype* x)
{
	*x = mylist.list[i];
}
int main()
{
	Seqlist mylist;
	int i, x;
	ListInitiate(&mylist);
	for (i = 0; i <10; i++)
	{
		int m = i + 1;
		ListInsert(&mylist, i,m);//插入十个元素
	}
	Listdelete(&mylist, 4, &x);//删除第4个元素
	for (i = 0; i < Listlength(mylist); i++)
	{
		Listget(mylist, i, &x);
		printf("%d  ", x);
	}
	return 0;
}