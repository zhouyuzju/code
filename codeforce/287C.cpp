#include <cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	if(n % 4 > 1)
		printf("-1\n");
	else{
		int a[n + 1];
		for(int i = 1,j = 1;j < n;j += 4,i += 2){
			a[i] = i + 1;
			a[i + 1] = n - (i - 1);
			a[n - i] = i;
			a[n - (i - 1)] = n - i;
		}	
		if(n % 2 == 1)
			a[(n + 1) / 2] = (n + 1) / 2;
		for(int i = 1;i <= n;i++)
			printf("%d%c",a[i],i == n ? '\n' : ' ');
	}
	return 0;
}
