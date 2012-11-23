#include<iostream>
using namespace std;
int main()
{
 int n, i;
 while(cin>>n&&n!=0)
 {
  for(i=0;n%2==0;i++)
  {n=n/2;}
  int sum=1;
  while(i)
  {
   i--;
   sum*=2;
  
  } cout<<sum<<endl;
  
 }
 return 0;
}