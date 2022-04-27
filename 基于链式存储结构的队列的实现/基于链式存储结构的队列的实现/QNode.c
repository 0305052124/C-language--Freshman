#define _CRT_SECURE_NO_WARNINGS 1
#include"QNode.h"
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
	QNode* p;
	p = Q->front->next; //ָ����еĵ�1���ڵ� 
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
//int QueueGet(LQueue Q, datatype* x)//ȡ��ͷԪ��
//{
//	//ȡ��ʽ����Q�ĵ�ǰ��ͷԪ�أ�������x��
//	//�ɹ�return 1��ʧ��return 0
//	//�Կ��ж�
//	if (Q.front == NULL)
//	{
//		printf("�����ѿգ���Ԫ�ؿ�ȡ�� \n");
//		return 0;
//	}
//	else
//	{
//		*x = Q.front->data;
//		return 1;
//	}
//}
int DeleteLQueue(LQueue* Q, datatype* x)//��Ԫ��*x������Q,�ɹ��򷵻�TRUE,���򷵻�FALSE 
{
	//ɾ����ʽ����Q�Ķ�ͷԪ�أ�������x
	QNode* p;
	if (Q->front == NULL)//�Կ��ж�
	{
		printf("�����ѿգ���Ԫ�س����У� \n");
		return 0;
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
		return 1;
	}
}

void DestroyLQueue(LQueue*  Q)//���ٶ��� ������̬����ռ�
{
	QNode* p, * p1;
	p = Q->front;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}
int  IsEmpty(LQueue*Q)//�ǿշ�
{
	//�ж���ʽ����Q�ǿշ񣬷ǿ�return 1������return 0
	if (Q->front == NULL)
	{
		return FALSE;
	}
	else return TRUE;
}
int Init_LQueue(LQueue* Q)//�Զ���Q���г�ʼ��(����ͷ�ڵ�),��ʼ���ɹ��򷵻�TRUE,���򷵻�FALSE
{
	Q->front = NULL;//�����ʼ��ͷָ���±�ֵ
	Q->rear = NULL;//�����ʼ��βָ���±�ֵ
	return TRUE;
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








