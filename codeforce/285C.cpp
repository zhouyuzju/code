#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int ori[n],input[n];
	for(int i = 0;i < n;i++){
		scanf("%d",&input[i]);
		ori[i] = i + 1;
	}
	sort(input,input + n);
	long long move = 0;
	for(int i = 0;i < n;i++)
		move += abs(ori[i] - input[i]);
	printf("%I64d\n",move);
	return 0;
}
