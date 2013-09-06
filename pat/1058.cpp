#include <iostream>
#include <cstdio>
#include <climits>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	int a[3],b[3],r[3];
	int mod[3] = {INT_MAX,17,29};
	scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
	scanf("%d.%d.%d",&b[0],&b[1],&b[2]);
	int carry = 0;
	for(int i = 2;i >= 0;i--){
		r[i] = (a[i] + b[i] + carry) % mod[i];
		carry = (a[i] + b[i] + carry) / mod[i];
	}
	printf("%d.%d.%d\n",r[0],r[1],r[2]);
	return 0;
}
