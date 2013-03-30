#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
#define MAX 100001
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		int a[101],b[101];
		for(int i = 0;i < n;i++){
			int ta,tb;
			scanf("%d%d",&ta,&tb);
			a[i] = ta;
			b[i] = tb;
		}
		int m;
		scanf("%d",&m);
		int happy[m + 1];
		happy[0] = 0;
		for(int i = 1;i <= m;i++){
			int tmpmax = -1;
			for(int j = 0;j < n;j++)	
				if(i >= b[j])
					tmpmax = max(tmpmax,happy[i - b[j]] + a[j]);
			happy[i] = max(tmpmax,happy[i - 1]);		
		}
		printf("%d\n",happy[m]);
	}
}
