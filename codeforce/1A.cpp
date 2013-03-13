/**
 *Easy problem about square cover
 *
 *2013/3/12
**/
#include<iostream>
#include<cmath>
using namespace std;

int main(){
	long long m,n,a;
	cin >> n >> m >> a;
	long long x,y;
	if(n % a == 0)
		x = n / a;
	else
		x = n / a + 1;
	if(m % a == 0)
		y = m / a;
	else
		y = m / a + 1;
	cout << x * y << endl;
}
