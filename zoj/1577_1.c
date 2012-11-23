#include<stdio.h>
#include<math.h>
int fun( int x,int y )
{
int t;
if( x < y )
{
   t = x;
   x = y;
   y = t;
}
while( y != 0 )
{
   t = x % y;
   x = y;
   y = t;
}
return x;
}
int main()
{
int M, N;
 double k;
 int i, sum = 0, l;
while( scanf("%d%d", &M, &N) != EOF )
{
   if( M == N )
    printf( "1\n" );
   else
   {
    l = M * N;
	sum=0;
    k = sqrt( l * 1.0 );
    for( i = M; i < k; i += M )
     if( l % i == 0 && ( fun( l / i, i ) == M ) )
      ++ sum;
    printf("%d\n", 2 * sum );
   }
}
return 0;
}