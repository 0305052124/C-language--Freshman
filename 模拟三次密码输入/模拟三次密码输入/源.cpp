#define _CRT_SECURE_NO_WARNINGS 1
//3.编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 
//密码错误，可以重新输入，最多输入三次。三次均错，则提示退出程序。
#include<stdio.h>
#include<string.h>
int main()
{
	int i = 0;
	char arr1[20] = { 0 };
	char arr2[20] = {"123456"};//密码
	for ( i = 0; i < 3;)
	{
      printf("请输入密码：");
	  scanf("%s", &arr1);
	  if (strcmp(arr1, arr2) == 0)//strcmp()比较两个字符串
	  {
		  printf("密码输入正确\n");
		  break;
	  }
	  else
	  {
		  i++;
	  }
	}
	if (i >= 3)
	{
		printf("密码已输入三次错误，退出系统\n");
	}
	return 0;
}



