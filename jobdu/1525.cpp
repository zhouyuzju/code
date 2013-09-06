#include <cstdio>
#include <cstring>
#define N 100001
char a[N];
void reverse(char *start, char *end)
{
    char tmp;
    while (start < end)
    {
        tmp = *start;
        *start = *end;
        *end = tmp;
        ++start;
        --end;
    }
}
void out(char *start, char *end)
{
    while (start <= end)
        printf("%c", *start++);
}
int main()
{
    int n;
    char *tmp, *p;
    while (scanf("%d", &n) != EOF && n)
    {
        getchar();
        gets(a);
        p = (char *) a;
        if (*p == ' ')
            printf(" ");
        while (*p)
        {
            if (*p == ' ')
            {
                p++;
                continue;
            }
            tmp = p;
            while (*p && *(++p) != ' ')
                ;
            reverse(tmp, p - 1);
            out(tmp, p - 1);
            if (*p)
                printf(" ");
  
        }
        printf("\n");
    }
    return 0;
}

