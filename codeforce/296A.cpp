#include <cstdio>
#include <map>
using namespace std;
int main(){
	int n;
	map<int,int> count;
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		int a;
		scanf("%d",&a);
		count[a]++;
		if(count[a] > (n + 1) / 2){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
