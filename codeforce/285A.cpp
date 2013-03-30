#include <cstdio>
using namespace std;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int s[n];
	for(int i = 0;i < n - k - 1;i++)
		s[i] = i + 1;
	for(int i = n - k - 1,j = 0;i < n;i++,j++)
		s[i] = n - j;
	for(int i = 0;i < n;i++)
		if(i != n - 1)
			printf("%d ",s[i]);
		else
			printf("%d\n",s[i]);
	return 0;
}
