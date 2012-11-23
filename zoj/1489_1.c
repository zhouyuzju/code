#include<stdio.h>

int modular(int a,long b,int n)
{
    long d,t ;
    d=1 ;
    t=a ;
    while(b>0)
    {
        if(b%2==1)
        d=d*t%n ;
        b=b/2 ;
        t=t*t%n ;
    }
    if(d==1)
    return 1 ;
    else return 0 ;
}

int main()
{
    long n ;
    long i ;
    while(scanf("%ld",&n)!=EOF)
    {
        if((n%2==0)||(n==1))
        {
            printf("2^? mod %ld = 1\n",n);
            continue ;
        }
        for(i=1;;i++)
        if(modular(2,i,n))
        {
            printf("2^%ld mod %ld = 1\n",i,n);
            break ;
        }

    }
    return 0 ;
}
