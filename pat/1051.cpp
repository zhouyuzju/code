#include <iostream>
#include <cstdio>
#include <stack>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	int M,N,K;
	scanf("%d%d%d",&M,&N,&K);
	for(int i = 0;i < K;i++){
		int popseq[N];
		for(int j = 0;j < N;j++)
			scanf("%d",&popseq[j]);
		int e = 1,idx = 0;
		stack<int> ss;
		ss.push(e);
		while(ss.size() <= M){
			while(ss.size() > 0 && ss.top() == popseq[idx]){
				ss.pop();
				idx++;
			}
			++e;
			if(e > N)
				break;
			ss.push(e);
		}
		if(ss.size() == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
