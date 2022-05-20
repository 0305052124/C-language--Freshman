#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef int DataType;
//1)直接插入排序
void InsertSort(int a[], int n, int order); //对数组前n个元素进行插入排序(order=0:为从小到大，order=1:为从大到小 
//2)希尔排序
void ShellSort(int a[], int n, int d[], int numOfD, int order);
//对数组前n个元素进行插入希尔插入排序order=0:为从小到大，order=1:为从大到小，d[]为增量数组，numOfD为增量数组的长度
//3)直接选择排序
void SelectSort(int a[], int n, int order); //对数组前n个元素进行选择排序(order=0:为从小到大，order=1:为从大到小 
//4)堆排序
void HeapSort(int a[], int n, int order); //对数组前n个元素进行堆排序(order=0:为从小到大，order=1:为从大到小 
void Print(int a[], int n);     //输出数组的前n个元素
void CreatHeap(DataType a[], int n, int h, int order);
void InitCreatHeap(DataType a[], int n);


int main()
{
	int a[10] = { 72,90,25,60,96,28,30,70,80,19 };
	printf("直接插入排序前：");
	Print(a, 10);
	InsertSort(a, 10, 0);
	printf("直接插入排序后: ");
	Print(a, 10);
	printf("\n");
	int b[12] = { 64,90,25,80,96,28,28,170,80,69,78,-9 };
	int m[3] = { 5,3,1 };
	printf("希尔排序前：");
	Print(b, 12);
	ShellSort(b, 12, m, 3, 0);
	printf("希尔排序后: ");
	Print(b, 12);
	printf("\n");
	int c[8] = { 23,90,35,60,16,28,40,70 };
	printf("直接选择排序前：");
	Print(c, 8);
	SelectSort(c, 8, 1);
	printf("直接选择排序后: ");
	Print(c, 8);
	printf("\n");

	int  d[12] = { 64, 90, 25, 80,96,28, 28, 170, 80,69,78,-9 };
	printf("堆排序前：");
	Print(d, 12);
	HeapSort(d, 12, 1);
	printf("堆排序后: ");
	Print(d, 12);
	printf("\n");
	return 0;
}
void CreatHeap(DataType a[], int n, int h, int order)  //n为数组a的元素个数 
{
	int i, j, flag;
	DataType temp;
	i = h;       //i为要建堆的二叉树跟节点下标 
	j = 2 * i + 1;   //j为i的左孩子节点的下标 
	temp = a[i];
	flag = 0;
	while (j < n && flag != 1)//沿左右孩子中值较大者重复向下筛选 
	{//寻找左右孩子节点中的较大值，j为其下标 
		if (order == 0)
		{
			if (j < n - 1 && a[j] < a[j + 1]) j++;
			if (temp > a[j]) flag = 1;
			else
			{
				a[i] = a[j];
				i = j;
				j = 2 * i + 1;
			}
		}
		else
		{
			if (j<n - 1 && a[j]>a[j + 1]) j++;
			if (temp < a[j]) flag = 1;
			else
			{
				a[i] = a[j];
				i = j;
				j = 2 * i + 1;
			}
		}

	}
	a[i] = temp;
}
void HeapSort(int a[], int n, int order)
{
	int i;
	DataType temp;
	for (int i = (n - 2) / 2; i >= 0; i--) CreatHeap(a, n, i, order);
	for (i = n - 1; i > 0; i--)
	{
		temp = a[0];
		a[0] = a[i];
		a[i] = temp;
		CreatHeap(a, i, 0, order);//调整跟节点 
	}
}

void SelectSort(int a[], int n, int order)
{
	int i, j, small;
	DataType temp;
	for (i = 0; i < n - 1; i++)
	{
		small = i;
		for (j = i + 1; j < n; j++)
		{
			if (order == 0)
			{
				if (a[j] < a[small])  small = j;
			}
			else
			{
				if (a[j] > a[small])  small = j;
			}
		}
		if (small != i)
		{
			temp = a[i];
			a[i] = a[small];
			a[small] = temp;
		}
	}
}

void ShellSort(int a[], int n, int d[], int numOfD, int order)
{
	int i, j, k, m, span;
	DataType temp;
	for (m = 0; m < numOfD; m++)
	{
		span = d[m];
		for (k = 0; k < span; k++)
		{
			for (i = k; i < n - span; i = i + span)
			{
				temp = a[i + span];
				j = i;
				if (order == 0)
				{
					while (j > -1 && temp < a[j])
					{
						a[j + span] = a[j];
						j = j - span;
					}
					a[j + span] = temp;
				}
				else
				{
					while (j > -1 && temp > a[j])
					{
						a[j + span] = a[j];
						j = j - span;
					}
					a[j + span] = temp;
				}
			}
		}
	}
}

void InsertSort(int a[], int n, int order)
{
	int i, j;
	DataType temp;
	for (i = 0; i < n - 1; i++)
	{
		temp = a[i + 1];
		j = i;
		if (order == 0)   //从小到大 
		{
			while (j > -1 && temp < a[j])
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = temp;
		}
		else     //从大到小 
		{
			while (j > -1 && temp > a[j])
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = temp;
		}
	}
}
void Print(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%3d ", a[i]);
	}
	printf("\n");
}
