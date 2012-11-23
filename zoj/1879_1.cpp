#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;
int main()
{
  int n,cnt,t,i,f;
  bitset<3001> chuan;
  while(cin >> n){
    //if(n==0) break;
    if(n==1){
      cin >> n;
      cout << "Jolly" << endl;
      continue;
    }
    cnt = n;
    n--;
    cin >> f;
    chuan.reset();
    while(n>0){
      cin >> t;
      if(abs(f-t)>0&&abs(f-t)<cnt)
    chuan.set(abs(f-t));      
      f = t;
      n--;
    }
    if(chuan.count()!=cnt-1)
    cout << "Not jolly" << endl;
    else
    cout << "Jolly" << endl;
  }
  return 0;
}
