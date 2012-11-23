#include <stdio.h>

int main(int argc, char *argv[])
{
    int n;

    while (scanf("%d", &n) != EOF) (n % 4 == 2) ? puts("yes") : puts("no");
    
    return 0;
}
