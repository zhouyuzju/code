#include<cstdio>
using namespace std;
int main(){
	int T,n,m;
	scanf("%d",&T);
	for(int i = 0;i < T;i++){
		scanf("%d%d",&n,&m);
		int count = 0;
		for(int j = 0;j < n;j++)
			for(int k = 0;k < m;k++){
				int g;
				scanf("%d",&g);
				if(g == 1)
					count++;
			}
		printf("%d\n",count);
	}
	return 0;
}
