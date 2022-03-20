#define _CRT_SECURE_NO_WARNINGS 1

#include"SeqCQueue.h"


void QueueInitiate(SeqCQueue* Q)//��ʼ��˳��ѭ������Q
{
	Q->rear = 0;//�����ʼ��βָ���±�ֵ
	Q->front = 0;//�����ʼ��ͷָ���±�ֵ
	Q->count = 0;//�����ʼ������ֵ
}


int  QueueNotEmpty(SeqCQueue  Q)//�ǿշ�
{
	//�ж�˳��ѭ������Q�ǿշ񣬷ǿ�return 1������return 0
	if (Q.count != 0) return 1;
	else return 0;
}


int QueueAppend(SeqCQueue* Q, DataType x)//�����
{
	//��x����˳��ѭ������Q�Ķ�β���ɹ�����1��ʧ�ܷ���0
	//�����жϣ���β��ȣ�count>0
	if (Q->count > 0 && Q->rear == Q->front)
	{
		printf("���������޷����룡 \n");
		return 0;
	}
	else
	{
		Q->queue[Q->rear] = x; //Ԫ��x�����β
		Q->rear = (Q->rear + 1) % MaxQueueSize;//��βָ���1
		Q->count++;//��������1
	}
}


int QueueDelete(SeqCQueue* Q, DataType* d)//������
{
	//ɾ��˳��ѭ������Q�Ķ�ͷԪ�أ�������d
	//�ɹ�return 1��ʧ��return 0
	//�Կ��ж�
	if (Q->count <= 0)
	{
		printf("�����ѿգ���Ԫ�س����У� \n");
		return 0;
	}
	else
	{
		*d=Q->queue[Q->front];//ȡ��ͷԪ�ش���d��
		Q->front = (Q->front + 1) % MaxQueueSize;//��ͷָ���1
		Q->count--;//��������1
		return 1;
	}
}


int QueueGet(SeqCQueue Q, DataType* d)//ȡ��ͷԪ��
{
	//ȡ˳��ѭ������Q�ĵ�ǰ��ͷԪ�أ�������b��
	//�ɹ�return 1��ʧ��return 0
	//�Կ��ж�
	if (Q.count <= 0)
	{
		printf("�����ѿգ���Ԫ�ؿ�ȡ�� \n");
		return 0;
	}
	else
	{
		*d = Q.queue[Q.front];
		return 1;
 }
}