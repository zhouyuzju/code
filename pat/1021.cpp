#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	vector<int> tree[n + 1];
	for(int i = 0;i < n - 1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	vector<int> visit = vector<int>(n + 1,0);
	int cnt = 0;
	for(int i = 1;i <= n;i++)
		if(visit[i] == 0){
			++cnt;
			queue<int> aqueue;
			aqueue.push(i);
			while(aqueue.size() > 0){
				int node = aqueue.front();
				aqueue.pop();
				for(int j = 0;j < tree[node].size();j++)
					if(visit[tree[node][j]] == 0){
						visit[tree[node][j]] = cnt;
						aqueue.push(tree[node][j]);
					}
			}
		}
	int max = 0;
	int zero = 0;
	for(int i = 1;i <= n;i++){
		if(visit[i] == 0)
			zero++;
		if(max < visit[i])
			max = visit[i];
	}
	if(max + zero > 1){
		printf("Error: %d components\n",max + zero);
		return 0;
	}
	int startNode,length;
	set<int> deepest;
	vector<bool> flag = vector<bool>(n + 1,false);
	queue<pair<int,int> > q;
	q.push(make_pair(1,1));
	flag[1] = true;
	while(q.size() > 0){
		int nodeNum = q.front().first;
		int step = q.front().second;
		q.pop();
		for(int i = 0;i < tree[nodeNum].size();i++)
			if(!flag[tree[nodeNum][i]]){
				flag[tree[nodeNum][i]] = true;
				q.push(make_pair(tree[nodeNum][i],step + 1));
			}
		if(q.size() == 0)
			startNode = nodeNum;
	}
	flag = vector<bool>(n + 1,false);
	deepest.insert(startNode);
	q.push(make_pair(startNode,1));
	flag[startNode] = true;
	while(q.size() > 0){
		int nodeNum = q.front().first;
		int step = q.front().second;
		q.pop();
		for(int i = 0;i < tree[nodeNum].size();i++)
			if(!flag[tree[nodeNum][i]]){
				flag[tree[nodeNum][i]] = true;
				q.push(make_pair(tree[nodeNum][i],step + 1));
			}
		if(q.size() == 0)
			length = step;
	}
	flag = vector<bool>(n + 1,false);
	deepest.insert(startNode);
	q.push(make_pair(startNode,1));
	flag[startNode] = true;
	while(q.size() > 0){
		int nodeNum = q.front().first;
		int step = q.front().second;
		if(step == length)
			deepest.insert(nodeNum);
		q.pop();
		for(int i = 0;i < tree[nodeNum].size();i++)
			if(!flag[tree[nodeNum][i]]){
				flag[tree[nodeNum][i]] = true;
				q.push(make_pair(tree[nodeNum][i],step + 1));
			}

	}
	for(set<int>::iterator it = deepest.begin();it != deepest.end();it++)
		printf("%d\n",*it);
	return 0;
}
