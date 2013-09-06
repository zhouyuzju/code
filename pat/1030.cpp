#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
struct Tripple{
	int node,distance,cost;
	Tripple(int x,int y,int z) : node(x), distance(y), cost(z){}
};

void dfs(vector<Tripple*> *graph,vector<int>& path,vector<int>& tmp,vector<bool>& visit,int startPoint,int endPoint,int distance,int minDis,int cost,int& minCost){
	if(distance > minDis)
		return;
	if(distance == minDis && startPoint == endPoint && cost < minCost){
		minCost = cost;
		path = vector<int>(tmp);
		path.push_back(endPoint);
		return;	
	}
	visit[startPoint] = true;
	tmp.push_back(startPoint);
	for(int i = 0;i < graph[startPoint].size();i++)
		if(!visit[graph[startPoint][i]->node])
			dfs(graph,path,tmp,visit,graph[startPoint][i]->node,endPoint,distance + graph[startPoint][i]->distance,minDis,cost + graph[startPoint][i]->cost,minCost);
	tmp.pop_back();
	visit[startPoint] = false;
}

int main(){
	int N,M,S,D;
	scanf("%d%d%d%d",&N,&M,&S,&D);
	vector<Tripple*> graph[N + 1];
	for(int i = 0;i < M;i++){
		int c1,c2,dis,cost;
		scanf("%d%d%d%d",&c1,&c2,&dis,&cost);
		graph[c1].push_back(new Tripple(c2,dis,cost));
		graph[c2].push_back(new Tripple(c1,dis,cost));
	}
	vector<int> distance = vector<int>(N + 1,INT_MAX);
	distance[S] = 0;
	while(true){
		bool update = false;
		for(int i = 0;i < N;i++)
			for(int j = 0;j < graph[i].size();j++){
				if(distance[i] != INT_MAX && distance[graph[i][j]->node] > distance[i] + graph[i][j]->distance){
					distance[graph[i][j]->node] = distance[i] + graph[i][j]->distance;
					update = true;
				}
			}
		if(!update)
			break;
	}
	int minDis = distance[D],minCost = INT_MAX;
	vector<int> tmp,path;
	vector<bool> visit = vector<bool>(N,false);
	dfs(graph,path,tmp,visit,S,D,0,minDis,0,minCost);
	for(int i = 0;i < path.size();i++)
		printf("%d ",path[i]);
	printf("%d %d\n",minDis,minCost);
	return 0;
}
