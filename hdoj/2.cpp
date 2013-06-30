#include <iostream>
#include <cstdio>
#define PI 3.1415927
using namespace std;
int main(){
	double d,t;
	int r,i = 1;
	while(true){
		cin >> d >> r >> t;
		if(r == 0)
			break;
		double distance = d * PI * r / 12 / 5280;
		double mph = distance / t * 3600;
		printf("Trip #%d: %.2f %.2f\n",i,distance,mph);
		i++;
	}
	return 0;
}
