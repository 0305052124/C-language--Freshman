#define _CRT_SECURE_NO_WARNINGS 1
//函数sstrcmp()的功能是对两个字符串进行比较。
// 当s数组中字符串和t数组中字符串相等时，返回值为0；
////当s数组中字符串大于t数组中字符串时，返回值大于0；
// 当s数组中字符串小于t数组中字符串时，返回值小于0
// （功能等同于库函数strcmp()）。
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
