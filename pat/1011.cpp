#include <iostream>
#include <cstdio>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	int index[3];
	double product = 1.0;
	for(int i = 0;i < 3;i++){
		double max = -1.0;
		double odd;
		for(int j = 0;j < 3;j++){
			scanf("%lf",&odd);
			if(odd > max){
				max = odd;
				index[i] = j;
			}
		}
		product *= max;
	}
	double profit = (product * 0.65 - 1.0) * 2;
	for(int i = 0;i < 3;i++){
		char c;
		if(index[i] == 0)
			c = 'W';
		else if(index[i] == 1)
			c = 'T';
		else
			c = 'L';
		printf("%c ",c);
	}
	printf("%.2f\n",profit);
	return 0;
}
