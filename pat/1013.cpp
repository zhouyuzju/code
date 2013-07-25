#include <iostream>
#include <cstdio>
#include <vector>
#define PR(x) cout << #x << " = " << x << endl
#define MAX 1001
using namespace std;

vector<int> graph[MAX];
bool visit[MAX];

void dfs(int start){
	int p = start;
	visit[p] = true;
	for(int i = 0;i < graph[start].size();i++)
		if(!visit[graph[start][i]])
			dfs(graph[start][i]);
}

int main(){
	int N,M,K;
	scanf("%d%d%d",&N,&M,&K);
	for(int i = 0;i < M;i++){
		int c1,c2;
		scanf("%d%d",&c1,&c2);
		graph[c1].push_back(c2);
		graph[c2].push_back(c1);
	}
	for(int i = 0;i < K;i++){
		int except;
		scanf("%d",&except);
		for(int j = 0;j <= N;j++){
			visit[j] = false;
		}

		int cnt = 0;
		visit[except] = true;
		for(int j = 1;j <= N;j++){
			if(visit[j] == 0){
				dfs(j);
				cnt++;
			}	
		}
		printf("%d\n",cnt - 1);
	}

	return 0;
}
