#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef int DataType;
//1)ֱ�Ӳ�������
void InsertSort(int a[], int n, int order); //������ǰn��Ԫ�ؽ��в�������(order=0:Ϊ��С����order=1:Ϊ�Ӵ�С 
//2)ϣ������
void ShellSort(int a[], int n, int d[], int numOfD, int order);
//������ǰn��Ԫ�ؽ��в���ϣ����������order=0:Ϊ��С����order=1:Ϊ�Ӵ�С��d[]Ϊ�������飬numOfDΪ��������ĳ���
//3)ֱ��ѡ������
void SelectSort(int a[], int n, int order); //������ǰn��Ԫ�ؽ���ѡ������(order=0:Ϊ��С����order=1:Ϊ�Ӵ�С 
//4)������
void HeapSort(int a[], int n, int order); //������ǰn��Ԫ�ؽ��ж�����(order=0:Ϊ��С����order=1:Ϊ�Ӵ�С 
void Print(int a[], int n);     //��������ǰn��Ԫ��
void CreatHeap(DataType a[], int n, int h, int order);
void InitCreatHeap(DataType a[], int n);


int main()
{
	int a[10] = { 72,90,25,60,96,28,30,70,80,19 };
	printf("ֱ�Ӳ�������ǰ��");
	Print(a, 10);
	InsertSort(a, 10, 0);
	printf("ֱ�Ӳ��������: ");
	Print(a, 10);
	printf("\n");
	int b[12] = { 64,90,25,80,96,28,28,170,80,69,78,-9 };
	int m[3] = { 5,3,1 };
	printf("ϣ������ǰ��");
	Print(b, 12);
	ShellSort(b, 12, m, 3, 0);
	printf("ϣ�������: ");
	Print(b, 12);
	printf("\n");
	int c[8] = { 23,90,35,60,16,28,40,70 };
	printf("ֱ��ѡ������ǰ��");
	Print(c, 8);
	SelectSort(c, 8, 1);
	printf("ֱ��ѡ�������: ");
	Print(c, 8);
	printf("\n");

	int  d[12] = { 64, 90, 25, 80,96,28, 28, 170, 80,69,78,-9 };
	printf("������ǰ��");
	Print(d, 12);
	HeapSort(d, 12, 1);
	printf("�������: ");
	Print(d, 12);
	printf("\n");
	return 0;
}
void CreatHeap(DataType a[], int n, int h, int order)  //nΪ����a��Ԫ�ظ��� 
{
	int i, j, flag;
	DataType temp;
	i = h;       //iΪҪ���ѵĶ��������ڵ��±� 
	j = 2 * i + 1;   //jΪi�����ӽڵ���±� 
	temp = a[i];
	flag = 0;
	while (j < n && flag != 1)//�����Һ�����ֵ�ϴ����ظ�����ɸѡ 
	{//Ѱ�����Һ��ӽڵ��еĽϴ�ֵ��jΪ���±� 
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
		CreatHeap(a, i, 0, order);//�������ڵ� 
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
		if (order == 0)   //��С���� 
		{
			while (j > -1 && temp < a[j])
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = temp;
		}
		else     //�Ӵ�С 
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
