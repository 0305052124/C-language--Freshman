#define _CRT_SECURE_NO_WARNINGS 1
//����һ��10������N��ת����һ��r����(r������2, 8, 16)���������
//���������ʽ���£�
//���룺18 2
//�����18 = (1000)2
//���룺1000  16
//�����1000 = (3EB)16
//���룺177  8
//�����177 = (261)8
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 100
typedef struct
{
    int data[SIZE];
    int top;
}seqstack;
void main()
{
    int N, r, x, sum;
    int A, B, C, D, E, F;
    printf("������һ��10�������ֺ�Ҫת���Ľ���: "); 
    scanf_s("%d%d", &N,&r);
    seqstack* s;
    s = (seqstack*)malloc(sizeof(seqstack));
    s->top = -1;
    printf("%d=(",N);
          while (N)//��˳���ջ
          {
              if (s->top != SIZE - 1)
              {
                  s->top++;
                  s->data[s->top] = N % r;
                  N = N / r;
              }
          } 
          while (s->top != -1)//��˳���ջ
            {
                x = s->data[s->top];
                if (x == 10) printf("A");
                if (x == 11) printf("B");
                if (x == 12) printf("C");
                if (x == 13) printf("D");
                if (x == 14) printf("E");
                if (x == 15) printf("F");
                if(x<10) printf("%d", x);
                s->top--;
            }
           printf(")%d", r);
}

