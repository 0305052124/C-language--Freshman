#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//异或运算相同为0，相异为1
//将数组里面所有的数字异或一遍，最终得到的那个数字就是只出现一次的数。
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