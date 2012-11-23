#include<stdio.h>
#include<stdlib.h>
int count(int n)
{
    if(n == 3)
    return 1;
    else if(n < 3)
    return 0;
    else if(n&1)
    {
          return count(n/2) + count(n/2 + 1);    
    }
    else {
            
         return count(n/2)* 2;
         }
    }
int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
      printf("%d\n",count(n));             
    }

    return 0;
    }