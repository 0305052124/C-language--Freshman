#define _CRT_SECURE_NO_WARNINGS 1

#include"LQNode.h"
void QueueInitiate(LQueue* Q)//��ʼ����ʽ����Q
{
	Q->front == NULL;//�����ʼ��ͷָ���±�ֵ
	Q->rear == NULL;//�����ʼ��βָ���±�ֵ
}
int  QueueNotEmpty(LQueue  Q)//�ǿշ�
{
	//�ж���ʽ����Q�ǿշ񣬷ǿ�return 1������return 0
	if (Q.front == NULL)
	{
		return 0;
	}
	else return 1;
}
void  QueueAppend(LQueue* Q, DataType x)//�����
{
	//��x������ʽ����Q�Ķ�β
	LQNode* p;
	p = (LQNode*)malloc(sizeof(LQNode));
	p->data = x;
	p->next = NULL;
	if (Q->rear != NULL) Q->rear->next = p;//����ԭ���ǿ�ʱ��β���½��
	Q->rear = p;//�޸Ķ�βָ��
	if (Q->front == NULL) Q->front = p;//����ԭ��Ϊ��ʱ�޸Ķ�ͷָ��
}
int QueueDelete(LQueue* Q, DataType* d)//������
{
	//ɾ����ʽ����Q�Ķ�ͷԪ�أ�������d
//�ɹ�return 1��ʧ��return 0
//�Կ��ж�
	LQNode* p;
	if (Q->front == NULL)
	{
		printf("�����ѿգ���Ԫ�س����У� \n");
		return 0;
	}
	else
	{
		*d = Q->front->data;
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
int QueueGet(LQueue Q, DataType* d)//ȡ��ͷԪ��
{
	//ȡ��ʽ����Q�ĵ�ǰ��ͷԪ�أ�������b��
	//�ɹ�return 1��ʧ��return 0
	//�Կ��ж�
	if (Q.front ==NULL)
	{
		printf("�����ѿգ���Ԫ�ؿ�ȡ�� \n");
		return 0;
	}
	else
	{
		*d = Q.front->data;
		return 1;
	}
}
void Destroy(LQueue Q)//������̬����ռ�
{
	LQNode* p, * p1;
	p =Q.front;
	while (p != NULL)
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}






