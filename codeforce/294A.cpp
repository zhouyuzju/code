#include <cstdio>
using namespace std;

int main(){
	int n,m;
	scanf("%d",&n);
	int a[n + 1];
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i = 0;i < m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x > 0)
			a[x - 1] += (y - 1);
		if(x < n)
			a[x + 1] += (a[x] - y);
		a[x] = 0;
	}
	for(int i = 1;i <= n;i++)
		printf("%d\n",a[i]);
	return 0;
}
