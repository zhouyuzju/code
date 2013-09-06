#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
map<string,int> cnt;
map<string,vector<string> > graph;
map<string,bool> visit;
map<string,int> result;

void dfs(string start,int& count,string& head,int& sum){
	if(cnt[start] > cnt[head])
		head = start;
	sum += cnt[start];
	count++;
	visit[start] = true;
	for(int i = 0;i < graph[start].size();i++)
		if(!visit[graph[start][i]])
			dfs(graph[start][i],count,head,sum);
	
}

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	for(int i = 0;i < N;i++){
		string n1,n2;
		int time;
		cin >> n1 >> n2 >> time;
		cnt[n1] += time;
		cnt[n2] += time;
		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
		visit[n1] = false;
		visit[n2] = false;
	}
	for(map<string,bool>::iterator it = visit.begin(); it != visit.end();it++)
		if(it->second == false){
			int count = 0;
			int sum = 0;
			string head = it->first;
			dfs(it->first,count,head,sum);
			if(count > 2 && sum / 2 > K)
				result[head] = count;
		}
	printf("%d\n",result.size());
	if(result.size() == 0)
		return 0;
	for(map<string,int>::iterator it = result.begin();it != result.end();it++)
		cout << it->first << " " << it->second << endl;
	return 0;
}

