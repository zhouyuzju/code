#include<stdio.h>
int main()
{
    int q[10002],n,l,r,i;
    while(scanf("%d",&n)!=EOF)
    {
        l=r=0;
        for(i=0;i<n;i++)
            scanf("%d",&q[i]);
        for (i=0;i<n;i++)  
        {
            if ((i%2==0 && q[i]==0) || (i%2!=0 && q[i]==1)) l++;  
            if ((i%2==0 && q[i]==1) || (i%2!=0 && q[i]==0)) r++; 
        }
        printf("%d\n",l<r?l:r);     
    }
    return(0);
}