#define _CRT_SECURE_NO_WARNINGS 1
//��ɲ�������Ϸ
// //�ɼ�����������һ�����֣��û��²�����֡�����´��ˣ�����ʾ�´��ˣ������С�ˣ�����ʾ��С�ˡ�
//���¶�ʱ�������û��¶��ˣ�����˵�����˼��Ρ�
//#include<stdio.h>
//#include<time.h>
//#include<stdlib.h>
//int main()
//{
//	int x = 0;
//	int count = 0;
//	srand(time(0));
//	int num = rand() % 100 + 1;  // �������һ��1-100֮�������
//	do {
//         printf("������0-100֮�������\n");
//	     scanf("%d", &x);
//		 count++;
//		 if (num > x)
//		 {
//			 printf("��С��\n");
//		 }
//		 if (num < x)
//		 {
//			 printf("�´���\n");
//		 }
//	} while (num!= x);
//	printf("�¶���\n");
//	printf("�����%d��\n",count);
//	return 0;
//}
//��������Ϸ������Ϸ���������һ��100���ڵ����������û�����һ����������в²⣬
// ��Ҫ���д�����Զ���������������ı��������бȽϣ�����ʾ���ˣ���Too big������
// ����С�ˣ���Too small��������ȱ�ʾ�µ��ˡ�����µ������������
// ����Ҫ��ͳ�ƲµĴ��������1�β³���������ʾ��Bingo!����
// ���3�����ڲµ�����������ʾ��Lucky You!����
// �������3�ε�����N�� > 3�������ڣ�������N�Σ��µ�����������ʾ��Good Guess!����
// �������N�ζ�û�вµ�������ʾ��Game Over��������������
// ����ڵ���N��֮ǰ���û�������һ��������Ҳ�����Game Over��������������
//
//�����ʽ : �����һ���и�������������100�����������ֱ�����Ϸ����������������Լ��²��������N��
//           ���ÿ�и���һ���û������룬ֱ�����ָ���Ϊֹ��
//
//�����ʽ : ��һ�������ÿ�β²���Ӧ�Ľ����ֱ������¶ԵĽ����Game Over���������
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	int guess = 0;
	int count = 0;
	srand(time(0));
    int n=0;
	int num = rand() % 100 + 1;
	printf("�ֱ�����µ����֡��Լ��²��������N\n");
	scanf("%d %d",&guess,&n);
    for (count =1;guess>0&&count <n;count++)
	{
		if (guess < num)
		{
			printf("Too small\n");
		}
		else if (guess > num)
		{
			printf("Too big\n");
		}
		else
		{
			break;
		}
		scanf("%d", &guess);
	
    }
	if (guess < 0 || n <= count)
	{
		printf("Game Over\n");
	}
	else if (count  == 1)
	{
		printf("Bingo!\n");
	}
	else if (count <= 3)
	{
		printf("Lucky You!\n");
	}
	else if (count <= n)
	{
		printf("Good Guess!\n");
	}
		return 0;
}
