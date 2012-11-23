#include<iostream>
using namespace std;
int main()
{
int i,j,k;
int n,a[100001];
k=1;
for(i=3;k<=100001;i++){
    if(i%3==0||i%5==0) {
   a[k]=i;
   k=k+1;
   }
   }
    while(cin>>n)
    {
      cout<<a[n]<<endl;
    }
    return 0;
}