#define _CRT_SECURE_NO_WARNINGS 1
//汉诺塔：汉诺塔(Tower of Hanoi)源于印度传说中，大梵天创造世界时造了三根金钢石柱子，
// 其中一根柱子自底向上叠着64片黄金圆盘。大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。
// 并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘。
//
//有三根杆子A, B, C。
// A杆上有N个(N > 1)穿孔圆盘, 盘的尺寸由下到上依次变小.要求按下列规则将所有圆盘移至C杆：
//1.每次只能移动一个圆盘
//2.小圆盘上不能放大圆盘
//可将圆盘临时置于B杆, 也可将从A杆移出的圆盘重新移回A杆, 但都必须尊循上述两条规则。求移动的过程。
#include<stdio.h>
void hanoi(int n, char A, char B, char C)
{
	if (n == 1)
	{
		printf("%c->%c\n", A, C);
	}
	else
	{
		hanoi(n - 1, A, C, B);
		printf("%c->%c\n", A, C);
		hanoi(n - 1, B, A, C);
	}
}
int main()
{
	int n;
	scanf("%d", &n);//有几个盘子
	char A, B, C;//三根柱子
	hanoi(n, 'A', 'B', 'C');

	return 0;
}
