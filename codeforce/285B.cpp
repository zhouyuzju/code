#include <cstdio>
using namespace std;
int main(){
	int n,s,t;
	scanf("%d%d%d",&n,&s,&t);
	int p[n + 1];
	bool flag[n + 1];
	for(int i = 0;i < n;i++){
		scanf("%d",&p[i + 1]);
		flag[i + 1] = false;
	}
	int count = 0;
	bool inf = false;
	while(s != t){
		//printf("%d,%d\n",s,t);
		if(flag[p[s]]){
			inf = true;
			break;
		}
		flag[p[s]] = true;
		s = p[s];
		count++;
	}
	if(inf)
		printf("%d\n",-1);
	else
		printf("%d\n",count);
}
