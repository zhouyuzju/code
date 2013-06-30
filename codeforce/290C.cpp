#include <cstdio>
using namespace std;

double max(double a,double b){
	if(a > b)
		return a;
	else
		return b;
}

int main(){
	int n;
	double m = -1;
	scanf("%d",&n);
	int s = 0;
	for(int i = 1;i <= n;i++){
		int d;
		scanf("%d",&d);
		s += d;
		m = max(m,s * 1.0 / i);
	}
	printf("%.6f",m);
}
