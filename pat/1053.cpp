#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

void dfs(map<int,vector<int> >& tree, vector<int>& path, int* weight, int root, int sum, int S){
	if(sum == S && tree[root].empty()){
		for(int i = 0;i < path.size();i++)
			printf("%d%c",path[i],i == path.size() - 1 ? '\n' : ' ');
		return;
	}
	if(tree[root].empty() || sum > S)
		return;
	vector<pair<int,int> > tmp;
	for(int i = tree[root].size() - 1;i >= 0;i--)
		tmp.push_back(make_pair(weight[tree[root][i]],tree[root][i]));
	sort(tmp.begin(),tmp.end());
	for(int i = tmp.size() - 1;i >= 0;i--){
		int child = tmp[i].second;
		path.push_back(weight[child]);
		dfs(tree,path,weight,child,sum + weight[child],S);
		path.pop_back();

	}
}

int main(){
	int N,M,S;
	scanf("%d%d%d",&N,&M,&S);
	map<int,vector<int> > tree;
	int weight[N];
	for(int i = 0;i < N;i++)
		scanf("%d",&weight[i]);
	for(int i = 0;i < M;i++){
		int id,num,child;
		scanf("%d%d",&id,&num);
		for(int j = 0;j < num;j++){
			scanf("%d",&child);
			tree[id].push_back(child);
		}
	}
	vector<int> path;
	path.push_back(weight[0]);
	dfs(tree,path,weight,0,weight[0],S);
	return 0;
}
