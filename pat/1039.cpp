#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define PR(x) cout << #x << " = " << x << endl
#define MAX 26 * 26 * 26 * 10 + 1
using namespace std;
vector<int> st[500001];
long query[MAX] = {0};

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	long cnt = 0;
	char name[5];
	for(int i = 0;i < K;i++){
		int id,num;
		scanf("%d%d",&id,&num);
		for(int j = 0;j < num;j++){
			scanf("%s",name);
			long stid = (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
			if(query[stid] == 0){
				cnt++;
				query[stid] = cnt;
			}
			st[query[stid]].push_back(id);
		}
	}
	for(int i = 0;i < N;i++){
		scanf("%s",name);
		long stid = (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
		int size = st[query[stid]].size();
		printf("%s %d",name,size);
		sort(st[query[stid]].begin(),st[query[stid]].end());
		for(int j = 0;j < st[query[stid]].size();j++)
			printf(" %d",st[query[stid]][j]);
		printf("\n");
	}
	return 0;
}
