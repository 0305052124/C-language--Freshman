#define _CRT_SECURE_NO_WARNINGS 1
//Linear Table On Sequence Structure
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAXSIZE  100
#define SUCCESS   0  //�ɹ�
#define FAIL 1  //ʧ��

typedef int DataType; //����Ԫ�����Ͷ���
DataType x;
DataType y;
DataType px;

typedef struct {  //˳���˳��ṹ���Ķ���
	DataType elem[MAXSIZE];
	int last;//���һ��Ԫ�ص�λ��
}SeqList;

//��������
void ListInitiate(SeqList* L);//��ʼ�����Ա�
int ListLength(SeqList* L);//�����Ա�ĳ��ȣ��������Ա�L������Ԫ�ظ���
int ListInsert(SeqList* L, int i, DataType x);//��iλ�ò���Ԫ��x������ɹ�����SUCCESS,����FAIL
int ListDelete(SeqList* L, int i); //ɾ�����е�i��Ԫ�أ�ɾ���ɹ�����SUCCESS,����FAIL
int ListSearch(SeqList* L, DataType x);//���ұ���Ԫ��x��λ�ã����ҳɹ�����λ�ã����򷵻�-1 
void ListPrint(SeqList* L);//�ã�a1,a2,a3,...,an)����ʽ������Ա�
int ListGet(SeqList* L, int i, DataType* px);//ȡ��i��Ԫ�أ����ҳɹ�����SUCCESS����Ԫ�ط���*px,����ʧ�ܷ���FAIL 

int main()
{
	SeqList L;  //����һ�����Ա� 
	//���ɲ˵� 
	char sel = ' ';
	while (sel != '0')
	{

		printf("------���Ա�(˳��洢�ṹ)��ʾϵͳ-------\n");
		printf("   �汾:1.0   ����:���� ����:2022/03/21\n");
		printf("------------------------------------------\n");
		printf("       1.��ʼ�����Ա�\n");
		printf("       2.����Ԫ��λ��\n");
		printf("       3.��λ�ò���Ԫ��\n");
		printf("       4.����һ��Ԫ��\n");
		printf("       5.ɾ��һ��Ԫ��\n");
		printf("       6.��ʾ�����Ա�\n");
		printf("       7.�����Ļ\n");
		printf("       8.�鿴���Ա���\n");
		printf("       0.�˳�ϵͳ\n");
		printf("������ѡ��[0-8]:\n");
		sel = getchar();
		switch (sel)
		{
		case '1':
			printf("��ʼ�����Ա����->\n");
			ListInitiate(&L);//��ʼ������
			ListPrint(&L);//�ٴ�ӡһ�����Ա�
			system("pause"); //����������� 
			break;
		case '2':
			DataType y;
			printf("����Ԫ�ز���->\n");
			printf("������Ҫ���ҵ�Ԫ�أ�");
			scanf("%d", &y);
			if (ListSearch(&L, y) == -1)
			{
				printf("����ʧ��\n");
			}
			else
			{
				printf("Ԫ��%d��ǰ��ַΪ��<%d>", y, ListSearch(&L, y));
			}
			ListPrint(&L);//�ٴ�ӡһ�����Ա�
			system("pause"); //����������� 
			break;
		case '3':
			int z;
			printf("��λ�ò���Ԫ�ز���->\n");
			printf("������Ҫ���ҵ�λ�ã�");
			scanf("%d", &z);
			if (ListGet(&L, z, &px) == -1)
			{
				printf("����ʧ��\n");
			}
			else
			{
				printf("��Ҫ���ַΪ<%d>�ĵ�ǰԪ��Ϊ��%d", z, px);
			}
			ListPrint(&L);//�ٴ�ӡһ�����Ա�
			system("pause"); //����������� 
			break;
		case '4':
			int i;
			printf("����һ��Ԫ�ز���->\n");
			printf("������Ҫ�����Ԫ�غ�λ�ã�");
			scanf("%d%d", &x, &i);
			ListInsert(&L, i, x);//���뺯��
			ListPrint(&L);//�ٴ�ӡһ�����Ա�
			system("pause"); //����������� 
			break;
		case '5':
			int x;
			printf("ɾ��һ��Ԫ�ز���->\n");
			printf("��Ҫɾ���ڼ���Ԫ�أ�\n");
			scanf("%d", &x);
			ListDelete(&L, x);//ɾ������
			ListPrint(&L);//�ٴ�ӡһ�����Ա�
			system("pause"); //����������� 
			break;
		case '6':
			printf("��ʾ���Ա����->\n");
			ListPrint(&L);
			system("pause"); //����������� 
			break;
		case '7':
			system("cls");
			break;
		case '8':
			printf("�鿴���Ա���->\n");
			printf("���Ա�ĳ���Ϊ��%d\n", ListLength(&L));
			system("pause"); //����������� 
			break;
		case '0':
			printf("\nллʹ�ã��ټ���\n");
			break;
		default:
			printf("�������ѡ��Ϸ���������ѡ��\n");

		}
	}
	return 0;
}
int ListGet(SeqList* L, int i, DataType* px)
{
	//ȡ���Ա��i��Ԫ�أ��ɹ�����SUCCESS����Ԫ�ط���*px,����ʧ�ܷ���FAIL
	if (L->last <= 0)
	{
		printf("���Ա�Ϊ��\n");
		return FAIL;
	}
	if (i<0 || i> L->last)//���Ա���û�������i��Ԫ��
	{
		printf("����i���Ϸ� \n");
		return FAIL;
	}
	else
	{
		*px = L->elem[i - 1]; //Ԫ�ط���* px
		return SUCCESS;
	}
}
void ListInitiate(SeqList* L)//��ʼ�����Ա�
{
	int m = 0;
	printf("��Ҫ������ٳ��ȵ����Ա�\n");
	scanf("%d", &m);
	L->last = m;
	for (int i = 0; i < L->last; i++)
	{
		L->elem[i] = i + 1;
	}
	//��ʼ�����Ա�Ϊ��1 2 3 4 5 6 7 8 9 10����������L->last �� m��
}

int ListLength(SeqList* L)//�����Ա�ĳ��ȣ��������Ա�L������Ԫ�ظ���
{
	return L->last;
}

int ListInsert(SeqList* L, int i, DataType x)//��iλ�ò���Ԫ��x������ɹ�����SUCCESS,����FAIL
{
	int j;
	if (i<0 || i>L->last)
	{
		printf("����i���Ϸ� \n");
		return FAIL;
	}
	else if (L->last >= MAXSIZE)
	{
		printf("���Ա������޷����� \n");
		return FAIL;
	}
	else
	{
		L->last++;    //���Ա���+1

		for (j = L->last; j > i - 1; j--)
		{
			L->elem[j] = L->elem[j - 1];//i��i�������������
		}
		L->elem[i - 1] = x;   //�����Ա��i��λ�ã��������±����x
		return SUCCESS;
	}
}

void ListPrint(SeqList* L)//�ã�a1,a2,a3,...,an)����ʽ������Ա�
{
	printf("\n���Ա�Ϊ��(");//���(
	int i;
	for (i = 0; i < L->last - 1; i++)
	{
		printf("%d,", L->elem[i]);
	}
	if (i == L->last - 1)
	{
		printf("%d", L->elem[i]);
	}
	printf(")\n");	//�����
}

int ListDelete(SeqList* L, int i) //ɾ�����е�i��Ԫ�أ�ɾ���ɹ�����SUCCESS,����FAIL 
{
	int j;
	if (i<0 || i> L->last)//���Ա���û�������i��Ԫ��
	{
		printf("����i���Ϸ� \n");
		return FAIL;
	}
	else if (L->last <= 0)
	{
		printf("���Ա��ѿ��޷����� \n");
		return FAIL;
	}
	else
	{
		for (j = i; j <= L->last; j++)//Ԫ��i��ɾ����i�����Ԫ��������ǰ��
		{
			L->elem[j - 1] = L->elem[j];
		}
		L->last--;//ɾ��Ԫ�غ󣬳���-1
		return SUCCESS;
	}
}


int ListSearch(SeqList* L, DataType x)//���ұ���Ԫ��x��λ�ã����ҳɹ�����λ�ã����򷵻�-1 
{
	if (L->last <= 0)
	{
		printf("���Ա�Ϊ��\n");
		return FAIL;
	}
	for (int j = 0; j < L->last; j++)
	{
		if (x == L->elem[j])
		{
			return j + 1;
		}
	}
	return FAIL;
}


