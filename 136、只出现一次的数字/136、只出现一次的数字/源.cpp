#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//���������ͬΪ0������Ϊ1
//�������������е��������һ�飬���յõ����Ǹ����־���ֻ����һ�ε�����
int singleNumber(int* nums, int numsSize)
{
	int ret = 0;
	for (int i = 0; i < numsSize; i++)
	{
		ret = nums[i] ^ ret;
	}
	return ret;
}
int main()
{
	int nums[3] = { 2,2,1 };
	printf("%d", singleNumber(nums, 3));
	return 0;
}