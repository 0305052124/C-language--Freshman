#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define PI 3.14159
#include<math.h>
//已知一个圆锥的底面半径是r = 3.5，高是h = 6.2，
// 求该圆锥的底面积，表面积，体积。
//注意：
//圆周率要采用define定义成常量，取值为3.14159。
//圆锥体的侧面积 = PI * r * L(注：扇形的面积 = n / 360 * PI * L * L = 弧度 * L * L / 2)
//圆锥体的全面积 = PI * r * L + PI * r2
//圆锥体的体积 = 1.0 / 3 * PI * r * r * h
//其中：PI为圆周率3.14159
//r为圆锥体底面圆的半径
//L为圆锥的母线长, L = sqrt(r2 + h2)
//


int main()
{
	float r = 3.5;
	float h = 6.2;
	float L = sqrt(r*r + h*h);
	printf("圆锥体的侧面积 = %f\n", PI * r * L);
	printf("圆锥体的全面积 = %f\n", PI * r * L + PI * r*r);
	printf("圆锥体的体积 = %f\n", 1.0 / 3 * PI * r * r * h);
	return 0;
}