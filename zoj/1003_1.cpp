#include<iostream>
#include<algorithm>
using namespace std;
int big , small;
int flag;
int search( int s , int b , int k )
{    
if ( b == 1 && s == 1 ) 
return 1;    
else    
{        
if( s == 1 ) 
flag = 1;        
for ( int i = k; i >= 2; i-- )        
{            
if ( s % i == 0 && search( s / i , b , i - 1 ) ) 
return 1;            
if ( b % i == 0 && search( s , b / i , i - 1 ) ) 
return 1;        
}        
return 0;    
} 
}
int main()
{    
while ( cin >> big >> small )    
{        
if( big < small ) 
swap( big , small );        
flag = 0;        
if ( search( small , big , 100 ) || !flag )            
cout << big << endl;        
else            
cout << small << endl;    
}
}