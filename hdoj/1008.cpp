#include <cstdio>
using namespace std;
int main(){
	int N;
	while(true){
		scanf("%d",&N);
		if(N == 0)
			break;
		int sum = 0,current = 0;
		for(int i = 0;i < N;i++){
			int f;
			scanf("%d",&f);
			int tmp;
			if(f - current > 0)
				tmp = (f - current) * 6;
			else if(f - current < 0)
				tmp = (current - f) * 4;
			else
				tmp = 0;
			sum +=  tmp + 5;
			current = f;
		}
		printf("%d\n",sum);
	}

}
