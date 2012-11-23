#include <stdio.h>
int distance(int A[5][5] , int x1 ,int y1 , int x2 , int y2)
{
   int i;
   int distance;
   if( ( x1 != x2 ) && (y1 != y2) )
       return -1;  
   if( x1 == x2 )
       if (y1 < y2)
       {
           for ( i = y1 , distance = 0 ;i <= y2 ; i++)
               distance = distance + A[x1][i];
           return distance;
       }
       else
       {
           for ( i = y2 , distance = 0 ;i <= y1 ; i++)
               distance = distance + A[x1][i];
           return distance;     
       }
       if( y1 == y2 )
           if (x1 < x2)
           {
               for ( i = x1 , distance = 0 ;i <= x2 ; i++)
                   distance = distance + A[i][y1];
               return distance;
           }
           else
           {
               for ( i = x2 , distance = 0 ;i <= x1 ; i++)
                   distance = distance + A[i][y1];
               return distance;     
           }
           return A[x1][y1];
}
int search( int A[5][5], int N)
{
   int i,j;
   for(i = 0;i < N;i++)
       for(j = 0;j < N;j++) 
           if( A[i][j] > 0 )
               return 1;
   return 0;
}
void change(int A[5][5] , int x , int y , int N)
{
   int i;
   for( i = 0; i < N ;i++)
   {
       if(distance (A , x , y , x , i) > 0 )
           A[x][i] = 0;
       if(distance (A , x , y , i , y) > 0 ) 
           A[i][y] = 0;
   }
}
int cot(int A[5][5] , int x , int y, int N)
{
   int i;
   int count;
   for( i = 0 ,count = 0; i < N ;i ++)
   {
       if(distance (A , x , y , x , i) > 0 && (i != y) )
           count++;
       if(distance (A , x , y , i , y) > 0 && (i != x) ) 
           count++;
   }
   return count;
}
void main()
{
   int num;
   int i,j;
   int xtemp,ytemp;
   char W[5][5]; 
   int T[5][5];
   int count,tcount;
   int max;
   while(scanf("%d",&num),num>0)
   {
       scanf("\n");
       for(i = 0;i < num;i++)
       { for(j = 0;j <= num;j++)
       scanf("%c",&W[i][j]) ;     
       }
       for(i = 0;i < num;i++)
           for(j = 0;j <= num;j++)
               T[i][j] = 0; 
       for(i = 0;i < num;i++)
           for(j = 0;j <= num;j++)
           {
               if(W[i][j] == '.')
                   T[i][j] = 1;
               else 
                   T[i][j] = -10; 
           }    
           max = 0;
           while(search(T , num) != 0)
           {
               tcount = 0;
               count = 16;
               for(i = 0 ; i < num ; i++)
                   for( j = 0; j < num ; j++)
                       if(T[i][j] > 0 )
                       {
                           tcount = cot(T , i , j , num);
                           if(tcount < count)
                           {
                               count = tcount;
                               xtemp = i;
                               ytemp = j;
                           }               

                       }  
                       change(T , xtemp , ytemp ,num);
                       max++;
           }    
           printf("%d\n",max);
   }
}
