#include <cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int a[2 * n + 1];
	for(int i = 0;i < n;i++)
		a[i] = i + 1;
	int i,j,c = 0;
	for(i = 2;i <= n;i++){
		for(j = i;j < n;j += i){
			int x = a[0 + c];
			a[0 + c] = a[j + c];
			a[j + c] = x;
		}
		a[n + c] = a[0 + c];
		c++;
	}
	for(int k = c;k < n + c;k++)
		printf("%d%c",a[k],k == n + c - 1 ? '\n' : ' ');

}
