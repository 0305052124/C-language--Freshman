#define _CRT_SECURE_NO_WARNINGS 1
//����sstrcmp()�Ĺ����Ƕ������ַ������бȽϡ�
//��s�������ַ�����t�������ַ������ʱ������ֵΪ0��
//��s�������ַ�������t�������ַ���ʱ������ֵ����0��
//��s�������ַ���С��t�������ַ���ʱ������ֵС��0�����ܵ�ͬ�ڿ⺯��strcmp()����
//int sstrcmp(char s[], char t[])
//{
//    int  i = 0, j = 0;
//    while (s[i] && t[j] && s[i] == t[j]);
//
//    return     s[i] - t[j];
//}
//int main()
//{
//    int  x;
//    char s1[50], s2[50];
//    scanf("%s%s", &s1, &s2);
//    x = sstrcmp(s1, s2);
//    printf("%d\n", x);
//    return 0;
//}
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[15];
    char str2[15];
    int ret;
    strcpy(str1, "abcdef");//��abcdef�ŵ�str1��Ŀ�����飩
    strcpy(str2, "ABCDEF");//��ABCDEF�ŵ�str2��Ŀ�����飩
    ret = strcmp(str1, str2);//��ASCII��ֵ��С�Ƚ�
    if (ret < 0)
    {
        printf("str1 С�� str2");
    }
    else if (ret > 0)
    {
        printf("str1 ���� str2");
    }
    else
    {
        printf("str1 ���� str2");
    }
    return 0;
}