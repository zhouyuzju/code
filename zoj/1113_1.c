#include "stdio.h"

void main()
{
   int n,i;
   double e,j;
   printf("n e\n");
   printf("- -----------\n");
   for ( n = 0;n <= 9;n++){
       j=1.0;
       e=0.0;

       for ( i = 0;i <= n; i++){
           if ( i==0 )
               j=1.0;
           else
               j=j*i;
           e=e+1.0/j;
       }

       if (n==0||n==1)
           printf("%d %1.0f\n",n,e);
       else if(n==2)
           printf("%d %1.1f\n",n,e);
       else
           printf("%d %1.9f\n",n,e);
    }
}