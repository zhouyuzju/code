#include <iostream>
#include <cstdio>
#include <cmath>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int num[n];
	double sum = 0.0;
	for(int i = 0;i < n;i++){
		scanf("%d",&num[i]);
		sum += num[i];
	}
	double avg = sum / n;
	sum = 0.0;
	for(int i = 0;i < n;i++)
		sum += pow(num[i] - avg, 2);
	printf("%.5f",sqrt(sum / n));
	return 0;
}
