#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

typedef int datatype;

//����Ԫ�ؽڵ����� ,�ṹ�嶨������ΪQNode
typedef struct node {
	datatype data;
	struct node* next;
}QNode;

//�ӽڵ�����, �����ͷ��βָ��
typedef struct {
	QNode* front, * rear;
}LQueue;

int Init_LQueue(LQueue* Q);
//������Q���г�ʼ��(����ͷ�ڵ�),��ʼ���ɹ��򷵻�TRUE,���򷵻�FALSE
int EnLQueue(LQueue* Q, datatype x);
//��Ԫ��x�����Q,�ɹ��򷵻�TURE,���򷵻�FALSE 
int DeleteLQueue(LQueue* Q, datatype* x);
//��Ԫ��*x�����Q,�ɹ��򷵻�TRUE,���򷵻�FALSE 
int IsEmpty(LQueue* Q);//�п� 
void PrintLQueue(LQueue* Q);  //�Ӷ�ͷ��ӡ����β
int  LengthLQueue(LQueue* Q); //������г��� 
void DestroyLQueue(LQueue* Q);  //���ٶ��� 

int main()
{
	LQueue Q;  //����һ������Q 
	int i = -1;
	int num = 0;
	int ret = 0;
	char sel = ' ';
	while (sel != '0')
	{

		printf("------����(��ʽ�洢�ṹ)��ʾϵͳ-------\n");
		printf("   �汾:1.0   ����:���� ����:2022-04-27\n");
		printf("------------------------------------------\n");
		printf("       1.��ʼ������\n");
		printf("       2.�����в���\n");
		printf("       3.�����в���\n");
		printf("       4.��ӡ���г���\n");
		printf("       5.��ӡ����(�Ӷ�ͷ����β��\n");
		printf("       6.�����Ļ\n");
		printf("       7.���ٶ���\n");
		printf("       0.�˳�ϵͳ\n");
		printf("������ѡ��[0-7]:");
		sel = getchar();
		switch (sel)
		{
		case '1':
			printf("��ʼ������.\n");
			Init_LQueue(&Q);
			system("pause");
			break;
		case '2':
			printf("�����в���.\n");
			printf("��Ҫ�뼸��Ԫ�أ�\n");
			scanf_s("%d", &i);
			printf("������%d��Ԫ�ص�ֵ\n", i);
			for (int j = 0; j < i; j++)
			{
				scanf_s("%d", &num);
				EnLQueue(&Q, num);
			}
			PrintLQueue(&Q);
			system("pause");
			break;
		case '3':
			printf("�����в���.\n");
			if (DeleteLQueue(&Q, &ret))
			{
				printf("���ӳɹ�\n");
				printf("����Ԫ��Ϊ��%d\n", ret);
			}
			else printf("����ʧ��\n");
			PrintLQueue(&Q);
			system("pause");
			break;
		case '4':
			printf("��ӡ���г��Ȳ���.\n");
			printf("���г���Ϊ��%d\n", LengthLQueue(&Q));//��ӡ���г��� 
			PrintLQueue(&Q);
			system("pause");
			break;
		case '5':
			printf("��ӡ���в���(�Ӷ�ͷ����β��).\n");
			PrintLQueue(&Q);  //�Ӷ�ͷ��ӡ����β
			system("pause");
			break;
		case '6':
			system("cls");
			break;
		case '7':
			printf("���ٶ���.\n");
			DestroyLQueue(&Q);  //���ٶ��� 
			PrintLQueue(&Q);
			system("pause");
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
int Init_LQueue(LQueue* Q)//�Զ���Q���г�ʼ��(����ͷ�ڵ�),��ʼ���ɹ��򷵻�TRUE,���򷵻�FALSE
{
	Q->front = NULL;//�����ʼ��ͷָ���±�ֵ
	Q->rear = NULL;//�����ʼ��βָ���±�ֵ
	return TRUE;

}
int  LengthLQueue(LQueue* Q)//������г��� 
{
	QNode* p;
	int count = 0;
	p = Q->front;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}
void PrintLQueue(LQueue* Q)
//�Ӷ�ͷ����β��ӡ����Q 
{
	printf("Ŀǰ����(�Ӷ�ͷ����β��)Ϊ��");
	QNode* p;
	p = Q->front; //ָ����еĵ�1���ڵ� 
	printf("(");
	while (p != NULL && p->next != NULL) //�������1���ڵ� 
	{
		printf("%d,", p->data);
		p = p->next;
	}
	if (p != NULL)  //��ӡ���1���ڵ� 
		printf("%d", p->data);
	printf(")\n");
}

int DeleteLQueue(LQueue* Q, datatype* x)//��Ԫ��*x������Q,�ɹ��򷵻�TRUE,���򷵻�FALSE 
{
	//ɾ����ʽ����Q�Ķ�ͷԪ�أ�������x
	QNode* p;
	if (Q->front == NULL)//�Կ��ж�
	{
		printf("�����ѿգ���Ԫ�س����У� \n");
		return FALSE;
	}
	else
	{
		*x = Q->front->data;
		p = Q->front;
		Q->front = Q->front->next;//�����н������
		if (Q->front == NULL)//ɾ�����һ�����ʱ��Ҫ�ö�βָ��Ϊ��
		{
			Q->rear = NULL;
		}
		free(p);
		return TRUE;
	}
}

void DestroyLQueue(LQueue* Q)//���ٶ��� ������̬����ռ�
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}
int  IsEmpty(LQueue* Q)//�ǿշ�
{
	//�ж���ʽ����Q�ǿշ񣬷ǿ�return 1������return 0
	if (Q->front == NULL)
	{
		return FALSE;
	}
	else return TRUE;
}

int EnLQueue(LQueue* Q, datatype x)//��Ԫ��x�����Q,�ɹ��򷵻�TURE,���򷵻�FALSE 
{
	//��x������ʽ����Q�Ķ�β
	QNode* p;
	p = (QNode*)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;
	if (Q->rear != NULL) Q->rear->next = p;//����ԭ���ǿ�ʱ��β���½��
	Q->rear = p;//�޸Ķ�βָ��
	if (Q->front == NULL) Q->front = p;//����ԭ��Ϊ��ʱ�޸Ķ�ͷָ��
	return TRUE;
}
