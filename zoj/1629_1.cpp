#include <iostream>

int array[505];

int main()
{
    int input;
    for ( int i = 1 ; i <= 500; ++i )
    {
        array[i] = array[i-1] + i*(i+1)/2 + i/2*(i-i/2);
    }
    
    while ( scanf( "%d", &input ) != EOF )
    {
        printf( "%d\n", array[input] );
    }
    
    return 0;
}
