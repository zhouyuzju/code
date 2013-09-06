#include <iostream>
#include <cstdio>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	int M,N;
	scanf("%d%d",&M,&N);
	int num = -1,cnt = 0;
	for(int i = 0;i < M;i++)
		for(int j = 0;j < N;j++){
			int tmp;
			scanf("%d",&tmp);
			if(cnt == 0){
				num = tmp;
				cnt = 1;
			}
			else if(num == tmp)
				cnt++;
			else
				cnt--;
		}
	printf("%d\n",num);
	return 0;
}
