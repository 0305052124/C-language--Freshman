#define _CRT_SECURE_NO_WARNINGS 1
//����sstrcmp()�Ĺ����Ƕ������ַ������бȽϡ�
// ��s�������ַ�����t�������ַ������ʱ������ֵΪ0��
////��s�������ַ�������t�������ַ���ʱ������ֵ����0��
// ��s�������ַ���С��t�������ַ���ʱ������ֵС��0
// �����ܵ�ͬ�ڿ⺯��strcmp()����
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
//    scanf("%s%s", s1, s2);
//    x = sstrcmp(s1, s2);
//    printf("%d\n", x);
//    return 0;
//}
