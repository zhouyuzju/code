#include <cstdio>
#include <algorithm>
#include <set>
#define MIN -2147483648
using namespace std;
int main(){
	int n;
	while(true){
		scanf("%d",&n);
		if(n == 0)
			break;
		int num[n],max = MIN;
		for(int i = 0;i < n;i++)
			scanf("%d",&num[i]);
		sort(num,num + n);
		for(int i = n - 1;i >= 0;i--)
			for(int j = 0;j < n;j++)
				for(int k = 0;k < n;k++){
					if(i == j || i == k || j == k)
						continue;
					int tmp = num[i] - num[j] - num[k];
					if(tmp != num[i] && tmp != num[j] && tmp!= num[k] && binary_search(num,num + n,tmp)){
						max = num[i];
						goto l;
					}
				}
l:
		if(max == MIN)
			printf("no solution\n");
		else
			printf("%d\n",max);
	}
	return 0;
}
