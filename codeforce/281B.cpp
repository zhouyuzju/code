/**
 * Greedy and brute force. Be careful when facing double data equal
 * Note that head file iostream have its own distance(a,b) function,
 * So do not name a funtion name with 'distance'.
 * 2013/3/19
 */

#include <iostream>
#include <cmath>
#define MIN 1e-20
using namespace std;
int x,y,n;

bool equal(double x,double y){
	return fabs(x - y) < MIN;
}

double dis(int a,int b){
	return fabs(x * 1.0 / y - a * 1.0 / b);
}

int main(){
	cin >> x >> y >> n;
	double fraction = x * 1.0 / y;
	int na = x,nb = n;
	for(int i = n;i >= 1;i--){
		for(int j = 0;j < 2;j++){
			int tmpx = int(fraction * i) + j;
			double tmpd = dis(tmpx,i);
			double d = dis(na,nb);
			if(equal(tmpd,d)){
				if(i < nb || tmpx < na)
					na = tmpx,nb = i;
			}
			else if(tmpd < d)
				na = tmpx,nb = i;	
		}
	}
	cout << na << "/" << nb << endl;
	return 0;
}
