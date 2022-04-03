#define _CRT_SECURE_NO_WARNINGS 1
//输入一个10进制数N，转换成一个r进制(r可以是2, 8, 16)的数输出。
//输入输出格式如下：
//输入：18 2
//输出：18 = (1000)2
//输入：1000  16
//输出：1000 = (3EB)16
//输入：177  8
//输出：177 = (261)8
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
    printf("请输入一个10进制数字和要转换的进制: "); 
    scanf_s("%d%d", &N,&r);
    seqstack* s;
    s = (seqstack*)malloc(sizeof(seqstack));
    s->top = -1;
    printf("%d=(",N);
          while (N)//按顺序进栈
          {
              if (s->top != SIZE - 1)
              {
                  s->top++;
                  s->data[s->top] = N % r;
                  N = N / r;
              }
          } 
          while (s->top != -1)//按顺序出栈
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

