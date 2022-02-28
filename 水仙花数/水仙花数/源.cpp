#define _CRT_SECURE_NO_WARNINGS 1
// “水仙花数”是指一个三位数，
// 
//2.求出0～999之间的所有“水仙花数”并输出。
//其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3 ? ，则153是一个“水仙花数”。
//在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），
//是指一N位数，其各个数之N次方和等于该数。
//例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
//153 = 1^3 + 5^3 + 3^3。
//370 = 3^3 + 7^3 + 0^3。
//371 = 3^3 + 7^3 + 1^3。
//407 = 4^3 + 0^3 + 7^3。
#include<stdio.h>
#include<math.h>
int main()
{
	int i = 0;
	int sum = 0;
	for (i = 100; i < 999; i++)
	{
		//pow(a,b)=a^b ,头文件math.h
		int c = i / 100;          //百位 
		int b = (i / 10) % 10;   //十位
		int a = i % 10;         //个位
		 sum = pow(a, 3) + pow(b, 3) + pow(c, 3);
		if (sum == i)
		{
			printf("%d\n",i);
		}
	}
	return 0;
}
