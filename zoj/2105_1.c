#include <stdio.h>
#include <string.h>
#define M 1000
int period[M];
int trans[10][10];
int main()
{
    int a, b, n, i;
    
    period[1] = period[2] = 1;
    while(scanf("%d%d%d", &a, &b, &n), a){
        memset(trans, 0, sizeof(trans));
        trans[1][1] = 2;
        for(i = 3; i <= n; i++){
            period[i] = (a * period[i - 1] + b * period[i - 2]) % 7;
            if(trans[period[i - 1] ][period[i] ])
                break;
            else
                trans[period[i - 1] ][period[i] ] = i;
        }
        if(i > n)
            printf("%d\n", period[n]);
        else{
            int p = trans[period[i - 1] ][period[i] ];
            int t = (n - p) % (i - p);
            printf("%d\n", period[p + t]);
        }
    }    
    return 0;
}