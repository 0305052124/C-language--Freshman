#define _CRT_SECURE_NO_WARNINGS 1
//����һ���������� nums �����������ҳ�����������ɵ����˻������������˻���
//
//���룺nums = [1, 2, 3]
//�����6
//
//���룺nums = [1, 2, 3, 4]
//�����24
//
//���룺nums = [-1, -2, -3]
//����� - 6
//
//3 <= nums.length <= 104
//- 1000 <= nums[i] <= 1000
#include<stdio.h>
//int maximumProduct(int* nums, int numsSize)
//{
//	int sum = 1;
//	if (numsSize == 3)
//	{
//		for (int i = 0; i < numsSize; i++)
//			sum *= nums[i];
//		return sum;
//	}
//	else
//	{
//		for (int i = 0; i < numsSize - 3; i++)
//		{
//			sum *= nums[i];
//			for (int j = i + 1; j < numsSize; j++)
//			{
//				sum *= nums[j];
//				sum *= nums[j + 1];
//			}
//		}
//	}
//}
//int maximumProduct(int* nums, int numsSize) {
//    // ��С�ĺ͵ڶ�С��
//    int min1 = INT_MAX, min2 = INT_MAX;
//    // ���ġ��ڶ���ĺ͵������
//    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
//
//    for (int i = 0; i < numsSize; i++) {
//        int x = nums[i];
//        if (x < min1) {
//            min2 = min1;
//            min1 = x;
//        }
//        else if (x < min2) {
//            min2 = x;
//        }
//
//        if (x > max1) {
//            max3 = max2;
//            max2 = max1;
//            max1 = x;
//        }
//        else if (x > max2) {
//            max3 = max2;
//            max2 = x;
//        }
//        else if (x > max3) {
//            max3 = x;
//        }
//    }
//
//    return fmax(min1 * min2 * max1, max1 * max2 * max3);
//}
//
//void sort(int* a, int left, int right)
//{
//    if (left >= right) return;
//    int i = left;
//    int j = right;
//    int key = a[i];
//    while (i < j)
//    {
//        while (i < j && key <= a[j])
//        {
//            j--;
//        }
//        a[i] = a[j];
//        while (i < j && key >= a[i])
//        {
//            i++;
//        }
//        a[j] = a[i];
//    }
//    a[i] = key;
//    sort(a, left, i - 1);
//    sort(a, i + 1, right);
//}
int* sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)                   //�Ƚ�n-1�Σ���һ��ѭ����ʾ������
    {
        for (j = 0; j < n - i - 1; j++)              // ���һ�αȽ�a[n-i-1]��a[n-i-2]   ���ڶ���ѭ����ʾ�Ƚϴ��� ��
        {
            if (a[j] < a[j + 1])
            {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
    return a;
}

int sum = 1;
int i = 0;
int FindMaxi(int* nums, int numsSize)
{
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] > 0 && nums[i + 1] < 0) return i;
    }
}
int maximumProduct(int* nums, int numsSize)
{
    if (numsSize < 3)  return 0;
    if (numsSize == 3)
    {
        for (int i = 0; i < numsSize; i++) sum *= nums[i];
        return sum;
    }
    else
    {
        sort(nums, numsSize);
        int ret1 = nums[0] * nums[1] * nums[2];//numsȫ��ȫ�����
        int ret2 = nums[0] * nums[numsSize-1] * nums[numsSize-2];
        return ret1>ret2 ? ret1:ret2;

    }
}
int main()
{
	int a[11] = { 1,2,3,4,5,6,-5,-9,-4,-2,-7};
	printf("%d\n",maximumProduct(a, 11));
	return 0;
}

