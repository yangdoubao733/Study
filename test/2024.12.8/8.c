#include <stdio.h>

int main()
{
    int d[10], a[26] = {0};
    char c[30];
    long long num;
    gets(c);
    scanf("%lld", &num);
    int n = 0;
    while (num != 0)
    {
        d[n] = num % 10;
        num /= 10;
        n++;
    }
    int i = 0;
    int p = 0;
    while (c[i] != '\0')
    {
        if (a[c[i] - 'A'] == 0)
        {
            a[c[i] - 'A'] = d[n - p - 1];
            printf("%d", d[n - p - 1]);
            p++;
        }
        else
        {
            printf("%d", a[c[i] - 'A']);
        }
        i++;
    }
    return 0;
}