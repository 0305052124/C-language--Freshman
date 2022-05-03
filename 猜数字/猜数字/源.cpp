#define _CRT_SECURE_NO_WARNINGS 1
//完成猜数字游戏
// //由计算机随机产生一个数字，用户猜测该数字。如果猜大了，会提示猜大了；如果猜小了，会提示猜小了。
//当猜对时，告诉用户猜对了，并且说明猜了几次。
//#include<stdio.h>
//#include<time.h>
//#include<stdlib.h>
//int main()
//{
//	int x = 0;
//	int count = 0;
//	srand(time(0));
//	int num = rand() % 100 + 1;  // 随机产生一个1-100之间的数字
//	do {
//         printf("请输入0-100之间的数字\n");
//	     scanf("%d", &x);
//		 count++;
//		 if (num > x)
//		 {
//			 printf("猜小了\n");
//		 }
//		 if (num < x)
//		 {
//			 printf("猜大了\n");
//		 }
//	} while (num!= x);
//	printf("猜对了\n");
//	printf("你猜了%d次\n",count);
//	return 0;
//}
//猜数字游戏是令游戏机随机产生一个100以内的正整数，用户输入一个数对其进行猜测，
// 需要你编写程序自动对其与随机产生的被猜数进行比较，并提示大了（“Too big”），
// 还是小了（“Too small”），相等表示猜到了。如果猜到，则结束程序。
// 程序还要求统计猜的次数，如果1次猜出该数，提示“Bingo!”；
// 如果3次以内猜到该数，则提示“Lucky You!”；
// 如果超过3次但是在N（ > 3）次以内（包括第N次）猜到该数，则提示“Good Guess!”；
// 如果超过N次都没有猜到，则提示“Game Over”，并结束程序。
// 如果在到达N次之前，用户输入了一个负数，也输出“Game Over”，并结束程序。
//
//输入格式 : 输入第一行中给出两个不超过100的正整数，分别是游戏机产生的随机数、以及猜测的最大次数N。
//           最后每行给出一个用户的输入，直到出现负数为止。
//
//输出格式 : 在一行中输出每次猜测相应的结果，直到输出猜对的结果或“Game Over”则结束。
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int pick = 5;
int guess(int num)
{
    if (pick < num)  return 1;
    else if (pick == num) return 0;
    else  return -1;
}
int guessNumber(int n)
{
    int left = 1, right = n;
    while (left < right)
    {  // 循环直至区间左右端点相同
        int mid = left + (right - left) / 2;  // 防止计算时溢出
        if (guess(mid) <= 0)
        {
            right = mid;  // 答案在区间 [left, mid] 中
        }
        else
        {
            left = mid + 1;  // 答案在区间 [mid+1, right] 中
        }
    }
    // 此时有 left == right，区间缩为一个点，即为答案
    return left;
}
int main()
{
    int n = 0;
    while (1)
    {
        printf("你猜几\n");
        scanf_s("%d", &n);
        if (guess(n) == 0)
        {
            printf("猜对了\n");
            printf("%d", n);
            break;
        }
        else if (guess(n) < 0) printf("猜小了\n");
        else printf("猜大了\n");
    }
        return 0;
}

//int main()
//{
//	int n = 0;
//	int count = 0;
//	srand(time(0));
//    int N=0;
//	int num = rand() % 100 + 1;
//	printf("分别输入猜的数字、以及猜测的最大次数N\n");
//	scanf("%d %d",&n,&N);
//    for (count =1;n>0&&count <N;count++)
//	{
//		if (n < num)
//		{
//			printf("Too small\n");
//		}
//		else if (n > num)
//		{
//			printf("Too big\n");
//		}
//		else
//		{
//			break;
//		}
//		scanf("%d", &n);
//    }
//	if (n < 0 || N <= count)
//	{
//		printf("Game Over\n");
//	}
//	else if (count  == 1)
//	{
//		printf("Bingo!\n");
//	}
//	else if (count <= 3)
//	{
//		printf("Lucky You!\n");
//	}
//	else if (count <= N)
//	{
//		printf("Good Guess!\n");
//	}
//		return 0;
//}