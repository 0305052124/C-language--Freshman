#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define PI 3.14159
#include<math.h>
//��֪һ��Բ׶�ĵ���뾶��r = 3.5������h = 6.2��
// ���Բ׶�ĵ������������������
//ע�⣺
//Բ����Ҫ����define����ɳ�����ȡֵΪ3.14159��
//Բ׶��Ĳ���� = PI * r * L(ע�����ε���� = n / 360 * PI * L * L = ���� * L * L / 2)
//Բ׶���ȫ��� = PI * r * L + PI * r2
//Բ׶������ = 1.0 / 3 * PI * r * r * h
//���У�PIΪԲ����3.14159
//rΪԲ׶�����Բ�İ뾶
//LΪԲ׶��ĸ�߳�, L = sqrt(r2 + h2)
//


int main()
{
	float r = 3.5;
	float h = 6.2;
	float L = sqrt(r*r + h*h);
	printf("Բ׶��Ĳ���� = %f\n", PI * r * L);
	printf("Բ׶���ȫ��� = %f\n", PI * r * L + PI * r*r);
	printf("Բ׶������ = %f\n", 1.0 / 3 * PI * r * r * h);
	return 0;
}