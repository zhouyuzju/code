#include <iostream>
#include <cstdio>

int main()
{
    int t;
    int ttt = 0;
    scanf( "%d", &t );
    while ( t-- )
    {
        int m,n;
        int tt = 0;
        if( ttt++ != 0)
        putchar( '\n');
        while (scanf( "%d%d",&n, &m ) && !( n == 0 && m == 0 ))
        {
            int answer = 0;
            for ( int i = 1; i < n; ++i )
            {
                for ( int j = i+1; j < n ; ++j )
                {
                    if ( (i*i+j*j+m)%(i*j) == 0 )
                    {
                        ++answer;
                    }
                }
            }
            printf( "Case %d: %d\n", ++tt, answer );
        }
    }
    return 0;
}
