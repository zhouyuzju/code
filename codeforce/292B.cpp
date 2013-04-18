#include <cstdio>
#define MAX 100001
using namespace std;
int main(){
	int n,m;
	int degree[MAX] = {0};
	scanf("%d%d",&n,&m);
	for(int i = 0;i < m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		degree[x]++;
		degree[y]++;
	}
	bool ring = true;
	int count = 0,count1 = 0;
	for(int i = 1;i <= n;i++)
		if(degree[i] != 2){
			ring = false;
			if(degree[i] == 1)
				count1++;
			count++;
		}
	if(ring)
		printf("ring topology\n");
	else if(count1 == n - 1 && count == n)
		printf("star topology\n");
	else if(count1 == 2 && count == 2)
		printf("bus topology\n");
	else
		printf("unknown topology\n");
	return 0;
}
