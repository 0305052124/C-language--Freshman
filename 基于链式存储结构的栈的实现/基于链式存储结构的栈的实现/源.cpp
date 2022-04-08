#define _CRT_SECURE_NO_WARNINGS 1
//Stack On Link Structure
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define FALSE   0  //ʧ�� 
#define TRUE    1  //�ɹ� 

typedef int DataType; //����Ԫ�����Ͷ���
DataType x;
typedef struct node
{
	DataType  data;
	struct node* next;
}LSNode, * LinkStack;
LinkStack head;
LinkStack top; //top����һ��ָ����� 

LinkStack CreateLinkStack();  //����һ���յ���ջ������ 
void  DestroyStack(LinkStack top);//�ͷ�ջ�����пռ�,����ͷ�ڵ� 
int IsEmpty(LinkStack top);//�п� 
void Push(LinkStack top, DataType x); //��ջ 
int Pop(LinkStack top, DataType* x); //��ջ 
int GetTop(LinkStack top, DataType* x); //ȥջ��Ԫ�� 
void PrintStack(LinkStack top); //��ӡջԪ��(��ջ����ջ��˳��) 
int main()
{	char sel = ' ';
	int num = 0;
	int ret = 0;
	while (sel != '0')//���ɲ˵� 
	{
		printf("------ջ(��ʽ�洢�ṹ)��ʾϵͳ-------\n");
		printf("   �汾:1.0   ����:���� ����:2022-04-07\n");
		printf("------------------------------------------\n");
		printf("       1.������ջ\n");
		printf("       2.��ջ����\n");
		printf("       3.��ջ����\n");
		printf("       4.��ӡջ��Ԫ��\n");
		printf("       5.��ӡջ\n");
		printf("       6.�����Ļ\n");
		printf("       7.�ͷ�ջ�ռ�\n");
		printf("       0.�˳�ϵͳ\n");
		printf("������ѡ��[0-7]:");
		sel = getchar();
		switch (sel)
		{
		case '1':
			printf("������ջ����.\n");
			head = CreateLinkStack();  //����һ���յ���ջ������ 
			system("pause");
			break;
		case '2':
			printf("��ջ����.\n");
			printf("�������ջԪ�ظ��� \n");//�Ľ���ջ���������������ջԪ������
			scanf_s("%d", &num);
			printf("�������ջԪ�� ");
			for (int i = 0; i < num; i++)
			{
				scanf_s("%d", &x);
				Push(head, x); //��ջ  
			}
			printf("��ջ����ջ��˳��Ϊ��");
			PrintStack(head);
			system("pause"); 
			break;
		case '3':
			printf("��ջ����.\n");
			
				if (Pop(head, &x))
				{
					printf("��ջԪ��Ϊ: %d\n", x);
				}
				else
				{
					printf("��ջʧ�� \n");
				}
			printf("��ջ����ջ��˳��Ϊ��");
					PrintStack(head);
			system("pause"); 
			break;
		case '4':
			printf("��ӡջ��Ԫ�ز���.\n");
			if (GetTop(head, &x))
			{
				printf("ջ��Ԫ��Ϊ%d \n", x);
				PrintStack(head);
			}
			else
				printf("ȡջ��Ԫ��ʧ�� \n");
			system("pause"); 
			break;
		case '5':
			printf("��ӡջ����.\n");
			PrintStack(head);
			system("pause"); 
			break;
		case '6':
			system("cls");
			break;
		case '7':
			printf("�ͷ�ջ�ռ����.\n");
			DestroyStack(head);
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

LinkStack CreateLinkStack()  //����һ���յ���ջ������ 
{
	LinkStack top = (LinkStack)malloc(sizeof(LSNode));
	if (top == NULL)
	{
		printf("�ڴ����ʧ��");
	}
	top->next = NULL;
	return top;
}
void PrintStack(LinkStack top) //��ӡջԪ��(��ջ����ջ��˳��) 
{
	LinkStack p = top->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int GetTop(LinkStack top, DataType* x) //ȡջ��Ԫ�أ�����ջ 
{
	LinkStack p = top->next;
	if (p == NULL)
	{
		printf("��ջ�ѿճ���");
		return FALSE;
	}
	*x = p->data;
	return TRUE;
}

void DestroyStack(LinkStack top)//�ͷ�ջ�����пռ�,����ͷ�ڵ� 
{
	LinkStack p, p1;
	p = top;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}
int IsEmpty(LinkStack top)//�п� 
{
	//�ж϶�ջ�Ƿ�ǿգ��ǿգ�return TRUE���գ�return FALSE
	if (top->next == NULL)
		return FALSE;
	else
		return TRUE;
}
void Push(LinkStack top, DataType x) //��ջ 
{
	//��Ԫ��x������ʽ��ջhead��ջ����Ϊ�µ�ջ��
	
	LinkStack p;
	p = (LinkStack)malloc(sizeof(LSNode));
	p->data = x;
	p->next = top->next;//�½������ջ��
	top->next = p;//�½���Ϊ�µ�ջ��
}
int Pop(LinkStack top, DataType* x)//��ջ 
{
	//��ջ����ջ��Ԫ����Ԫ��x���أ�����ջ�ɹ�return 1��ʧ��return 0��
	LinkStack p = top->next;
	if (p == NULL)
	{
		printf("��ջ�ѿճ���\n");
		return FALSE;
	}
	else
	{
		top->next = p->next;
		*x = p->data;
		free(p);
		return TRUE;
	}
}