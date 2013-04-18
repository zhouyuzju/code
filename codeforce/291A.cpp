#include <cstdio>
#include <map>
using namespace std;

int main(){
	int n,count = 0;
	map<int,int> v;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		int k;
		scanf("%d",&k);
		if(k == 0)
			continue;
		if(v[k] == 0)
			v[k]++;
		else if(v[k] == 1){
			count++;
			v[k]++;
		}
		else if(v[k] == 2){
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n",count);
	return 0;
}


