#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(){
	double balance,sum = 0.0;
	for(int i = 0;i < 12;i++){
		cin >> balance;
		sum += balance;
	}
	printf("$%.2f\n",round(sum / 12 * 100) * 1.0 / 100);
	return 0;
}
