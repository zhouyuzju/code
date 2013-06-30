/**
 *
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define PR(x) cout << #x << " = " << x << endl
#define MAX 100
using namespace std;



int main(){
	int N,M;
	scanf("%d%d",&N,&M);
	vector<int> tree[MAX];
	for(int i = 0;i < M;i++){
		int id,k;
		scanf("%d%d",&id,&k);
		for(int i = 0;i < k;i++){
			int idk;
			scanf("%d",&idk);
			tree[id].push_back(idk);
		}
	}
	queue<int> q;
	q.push(1);
	while(q.size() > 0){
		int count = 0;
		vector<int> next;
		while(q.size() > 0){
			int id = q.front();
			q.pop();
			if(tree[id].size() > 0){
				for(int i = 0;i < tree[id].size();i++)
					next.push_back(tree[id][i]);
			}
			else
				count++;
		}
		printf("%d%c",count,next.size() > 0 ? ' ' : '\n');
		for(int i = 0;i < next.size();i++)
			q.push(next[i]);
	}
	return 0;
}

