//====================================
//
// 代码框架
//====================================
#include <stdio.h>
#include <string.h>
#define N 26

// 判断字符串s和数字num 是否匹配，即是否能通过字符串s构造出num，例如ABB 和 100是匹配的，而ABB和101则不匹配。
// 如果匹配，函数返回1，否则返回0
// 字符串与数字的匹配方法参见综合题（二）, 匹配过程中要考虑已经出现过的字母
// 数组a[]是字母表数组，用于记录和快速查询字母所对应的数字
// 数组d[]是数字数组, 用于记录每一位数字
// 数组nc[]用于记录每一位数字对应的字母
int isvalid(char *s, int num, int a[], int d[], int nc[])
{

    int n = 0;
    while (num != 0)
    {
        d[n] = num % 10;
        num /= 10;
        n++;
    }
    int i = 0;
    int p = 0;
    int target = 1;
    while (s[i] != '\0')
    {
        if (a[s[i] - 'A'] == -1)
        { // 判断该字母是否为第一次出现
            a[s[i] - 'A'] = d[n - p - 1];
        }
        else if (a[s[i] - 'A'] != d[n - p - 1])
        { // 判断该字母对应数字与当前位数字是否一致
            target = 0;
        }

        if (nc[d[n - p - 1]] == -1)
        { // 判断该数字是否第一次出现
            nc[d[n - p - 1]] = s[i];
        }
        else if (nc[d[n - p - 1]] != s[i])
        { // 判断该数字对应字母与当前字母是否一致
            target = 0;
        }
        i++;
        p++;
    }
    return target;
}

//
// s1 和 s2是两个字符串，s3是s1和s2的和，函数返回满足这个等式的数字组合的总数量
// 检查匹配关系时，需要检查s1和i，s2和j, 以及 s3和i+j是否同时满足匹配条件，如果满足，则得到一组符合加法等式的字母组合。
//
int countnum(char *s1, char *s2, char *s3)
{
    int count = 0;
    int a[N];
    int d[10];
    int nc[10];
    for (int i = 100; i <= 899; i++)
    {
        for (int j = 100; j <= 999 - i; j++)
        {
            for (int i = 0; i < 26; i++) // 对字母表数组a[]进行初始化
                a[i] = -1;

            for (int i = 0; i < 10; i++) // 对数字数组d[]进行初始化
                d[i] = -1;

            for (int i = 0; i < 10; i++) // 对数字数组num[]进行初始化
                nc[i] = -1;
            if (isvalid(s1, i, a, d, nc) && isvalid(s2, j, a, d, nc) && isvalid(s3, i + j, a, d, nc))
            {
                count += 1;
            }
        }
    }
    return count;
}

int main()
{

    char num1[4];
    char num2[4];
    char num3[4];
    scanf("%s", num1);
    scanf("%s", num2);
    scanf("%s", num3);

    int cnt = countnum(num1, num2, num3);
    printf("%d\n", cnt);

    return 0;
}

// （做法）佛祖保佑程序能跑
// 我是sb