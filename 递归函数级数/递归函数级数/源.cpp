#define _CRT_SECURE_NO_WARNINGS 1
//编写一个递归函数，计算下面的级数：
//
//编写测试程序，计算i = 1, i = 10, i = 100, i = 1000时候的值。
//程序代码及测试结果：
//#include<stdio.h>
//double fib(int i)
//{
//	if (i == 1) return 1.0;
//	else
//	{
//		return fib(i - 1) + (1.0 / i);
//	}
//}
//int main()
//{
//	int i;
//	scanf("%d", &i);
//	printf("%lf", fib(i));
//	return 0;
//}


//用递归方法实现一个整数的倒置输出，如输入整数：123，输出为：321。
//测试用例：5, 38, 1307, 23078
//程序代码及测试结果：
//#include<stdio.h>
//int Swap(int x)
//{
//	if (0<x&&x<10) printf("%d",x);
//	else
//	{
//		printf("%d", x%10);
//		return Swap(x / 10);
//	}
//}
//int main()
//{
//	int x;
//	scanf("%d", &x);
//	Swap(x);
//	return 0;
//}

//计算最大公约数gcd(m, n)，用递归形式定义如下：
//?	若m%n==0，则gcd(m, n)==n
//?	否则，gcd(m, n)==gcd(n, m%n)。
//      用递归方式编写函数gcd(m, n)
//编写测试程序求公约数(1, 8)，(3, 93), (27, 0), (9885, 7651)

//#include<stdio.h>
//int gcd(int m, int n)
//{
//	if (m == 0 || n == 0) return 0;
//	else if (m % n == 0) return n;
//	else gcd(n, m % n);
//}
//int main()
//{
//	int m,n;
//	scanf_s("%d%d", &m,&n);
//	printf("%d", gcd(m,n));
//	return 0;
//}

//问题4：给定整数a1、a2、…、an，判断是否可以从中选出若干数，使它们的和恰好为k。其中
//
//样例：
//输入
//n = 4
//a = { 1,2,4,7 }
//k = 13
//输出
//Yes(13 = 2 + 4 + 7)
//
//输入
//n = 4
//a = { 1,2,4,7 }
//k = 15
//输出
//No
//程序代码及测试结果：
//#include<stdio.h>
//int flag = 0;//标志符号：记录有没有解  
//int pick[6] = { 0 };//记录要打印的物品的下标  
//int N = 0;//记录打印答案的个数  
//
//int Find(int n, int k, int a[],int m)
//{
//	if (k < 0 || n < 1) return 0;
//	else if (k == 0)
//	{
//		printf("YES{ %d = ",m);
//		for (int i = 0; i < N; i++)
//		{
//			if (i == N - 1)
//			{
//				printf("%d", a[pick[i]]);
//			}
//			
//			else printf("%d + ", a[pick[i]]);
//
//		}
//		printf("}");
//		flag = 1;
//		return 1;
//	}
//	else
//	{
//		Find(n - 1,k, a,m );           //所选物品不包括w[n-1]
//		pick[N++] = n - 1;           //记录要打印的物品的下标  
//		Find(n - 1, k - a[n - 1] ,a,m);// 所选物品包括w[n-1]	
//		N--;    //把最后一个N-1
//	}
//	return flag;
//}
//int main()
//{//跟背包问题一样
//	int n=0;
//	int k=0;
//	int a[20] = { 0 };
//	printf("有几个定整数：\n");
//	scanf_s("%d", &n);
//	printf("请输入%d个整数\n", n);
//	for (int i = 0; i < n; i++)
//	{
//		scanf_s("%d", &a[i]);
//	}
//	printf("输入你想要的k：");
//	scanf_s("%d", &k);
//	if(Find(n, k, a,k))
//		printf(" ");
//	else
//		printf("NO\n");
//	return 0;
//}


//问题5：给定一个大小为NxM的迷宫。迷宫有通道和墙壁组成，每一步可以向邻接的上下左右四格通道移动。
// 请求从起点到终点所需的最小步数。
// 请注意:本题假定从起点一定可以移动到终点，其中N,M<=100
// 
//样例：N = 10, M = 10 (‘#’, ’.’, ’S’, ’G’分别表示墙壁、通道、起点和终点)
//#S######.#
//......#..#
//.#.##.##.#
//.#........
//##.##.####
//....#....#
//.#######.#
//....#.....
//.####.###.
//....#...G#
//输出：22
// 


