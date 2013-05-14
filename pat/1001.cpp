#include <cstdio>
#include <iostream>
#include <string>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
void pn(int n){
	bool pos = n >= 0 ? true : false;
	n = n > 0 ? n : -n;
	int digit[10];
	int count = 0;
	while(n > 0){
		digit[count] = n % 10;
		count++;
		n /= 10;
	}
	if(count == 0){
		printf("%d\n",n);
		return;
	}
	if(!pos)
		printf("-");
	for(int i = count - 1;i >= 0;i--){
		if(i % 3 == 0 && i >= 3)
			printf("%d,",digit[i]);
		else
			printf("%d",digit[i]);
	}
	printf("\n");
}

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	pn(a + b);
	return 0;
}
