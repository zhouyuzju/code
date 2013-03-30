#include <cstdio>
#include <cmath>
int low(int n){
	int c = 0;
	while(n > 0){
		if(n % 2 != 0)
			break;
		c++;
		n /= 2;
	}
	return int(pow(2,c));
}

using namespace std;
int main(){
	int n;
	while(true){
		scanf("%d",&n);
		if(n == 0)
			break;
		printf("%d\n",low(n));
	}
	return 0;
}
