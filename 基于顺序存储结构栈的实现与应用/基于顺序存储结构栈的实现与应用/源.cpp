#define _CRT_SECURE_NO_WARNINGS 1
//Stack On Sequence Structure
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define Stack_Size  100
#define FALSE   0
#define TRUE    1

typedef int DataType; //����Ԫ�����Ͷ���
DataType x;

//˳��ջ�Ķ���
typedef struct {  
	DataType  elem[Stack_Size];//Stack��ʾ˳���ջ���Ԫ�ص�����
	int top;//top��ʾ˳���ջ����Stack�ĵ�ǰջ��λ��
}SeqStack;

void  InitStack(SeqStack* S);//��ʼ��ջ 
int IsEmpty(SeqStack* S);//�п� 
int IsFull(SeqStack* S);//���� 
int Push(SeqStack* S, DataType x); //��ջ 
int Pop(SeqStack* S, DataType* x); //��ջ 
int GetTop(SeqStack S, DataType* x); //ȡջ��Ԫ�� 
void PrintStack(SeqStack* S); //��ӡջԪ��(��ջ����ջ��˳��) 

int main()
{
	SeqStack S;  //����һ�����Ա� 
	char sel = ' ';
	while (sel != '0')//���ɲ˵� 
	{
		printf("------ջ(˳��洢�ṹ)��ʾϵͳ-------\n");
		printf(" �汾:1.0 ����:���� ����:2022-04-01\n");
		printf("------------------------------------------\n");
		printf("       1.��ʼ��ջ\n");
		printf("       2.��ջ����\n");
		printf("       3.��ջ����\n");
		printf("       4.��ӡջ��Ԫ��\n");
		printf("       5.��ӡջ\n");
		printf("       6.�����Ļ\n");
		printf("       0.�˳�ϵͳ\n");
		printf("������ѡ��[0-6]:\n");
		sel = getchar();
		int i;
		switch (sel)
		{
		case '1':
			printf("��ʼ��ջ.\n");
			InitStack(&S);
			system("pause");
			break;
		case '2':
			printf("��ջ����.\n");
			printf("��ջ֮���Ԫ������Ϊ�� ");
			for (i = 0; i < 10; i++)
			{
				Push(&S, i+1); 
			}
			PrintStack(&S); //��ӡջԪ��(��ջ����ջ��˳��)  
			system("pause"); 
			break;
		case '3':
			printf("��ջ����.\n");
			Pop(&S, &x);
			printf("��ջԪ��Ϊ��%d\n", x);
			PrintStack(&S); //��ӡջԪ��(��ջ����ջ��˳��)  
			system("pause"); 
			break;
		case '4':
			printf("��ӡջ��Ԫ�ز���.\n");
			GetTop( S, &x);
			printf("��ǰջ��Ԫ��Ϊ��%d\n", x);
			PrintStack(&S); //��ӡջԪ��(��ջ����ջ��˳��)
			system("pause");
			break;
		case '5':
			printf("��ӡջ����.\n");
			PrintStack(&S); //��ӡջԪ��(��ջ����ջ��˳��)  
			system("pause"); 
			break;
		case '6':
			system("cls");
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

void  InitStack(SeqStack* S)//��ʼ��ջ 
{
	S->top = 0;//��ʼ��һ����ջ����ʼ��ջ���±�ֵ��top=0��ʾ��ջΪ��ջ
}

int IsEmpty(SeqStack* S)//�п�
{
	//�ж�˳���ջS�ǿշ����ǿշ���FALSE���շ���TRUE
	if (S->top <= 0)
		return FALSE;
	else
		return TRUE;
}

int IsFull(SeqStack* S)//���� 
{
	//�ж�˳���ջS����������������FALSE����������TRUE
	if (S->top >= Stack_Size)
	{
		printf("��ջ�����޷�����! \n");
		return FALSE;
	}
	else
		return TRUE;
}
int Push(SeqStack* S, DataType x) //��ջ
{
	//��x����˳���ջS�У�����ջ�ɹ��򷵻�TRUE��ʧ�ܷ���FALSE
	if (S->top >= Stack_Size)//�ж�ջ��
	{
		printf("��ջ�����޷�����! \n");
		return FALSE;
	}
	else
	{
		S->top++;//ָ���1����Ԫ��, return
		S->elem[S->top-1] = x;
		return TRUE;
	}
}
int Pop(SeqStack* S, DataType* x)//��ջ 
{
	//ȡ��˳��ջ��S��ջ��Ԫ�أ��ɲ���x����
	//��ջ�ɹ�����TRUE��ʧ�ܷ���FALSE
	//ʧ�������ջ�գ���Ԫ�ؿɳ�ջ
	if (S->top <= 0)
	{
		printf("��ջ�ѿ��޷���ջ! \n");
		return FALSE;
	}
	else//ջ�ǿգ�ȡԪ�أ���ָ�룬return
	{
		S->top--;
		*x = S->elem[S->top];
		return TRUE;
	}
}
int GetTop(SeqStack S, DataType* x) //ȡջ��Ԫ��
{
	//ȡ˳���ջS�ĵ�ǰջ��Ԫ�أ��ɲ���x����
	//�ɹ�����TRUE��ʧ�ܷ���FALSE
	
	if (S.top <= 0)//ʧ�������ջ�գ���Ԫ�ؿ�ȡ
	{
		printf("��ջ�ѿ�,��Ԫ�ؿ�ȡ! \n");
		return FALSE;
	}
	else//ջ�ǿգ�ȡԪ�أ���ָ�룬return
	{
		*x = S.elem[S.top-1];
		return TRUE;
	}
}
void PrintStack(SeqStack* S) //��ӡջԪ��(��ջ����ջ��˳��) 
{
	int i = 0;
	while(i<S->top)
	{
		printf("%d ", S->elem[i]);
		i++;
	}
	printf("\n ");
}











