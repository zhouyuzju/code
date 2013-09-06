/**
 * http://acm.hdu.edu.cn/showproblem.php?pid=2544
 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	while(true){
		int V,E;
		scanf("%d%d",&V,&E);
		int S = 1, F = V;
		if(V == 0 && E == 0)
			break;
		vector<vector<pair<int,int> > > graph(V + 1,vector<pair<int,int> >());
		vector<int> d(V + 1,INT_MAX);
		vector<bool> relax(V + 1,false);
		d[S] = 0;
		int a,b,e;
		for(int i = 0;i < E;i++){
			scanf("%d%d%d",&a,&b,&e);
			graph[a].push_back(make_pair(b,e));
			graph[b].push_back(make_pair(a,e));
		}
		for(int i = 0;i < V;i++){
			int minDis = INT_MAX;
			int node = -1;
			for(int j = 1;j <= V;j++)
				if(!relax[j] && d[j] < minDis){
					node = j;
					minDis = d[j];
				}
			for(int j = 0;j < graph[node].size();j++)
				if(d[graph[node][j].first] > d[node] + graph[node][j].second)
					d[graph[node][j].first] = d[node] + graph[node][j].second;
			relax[node] = true;
		}

		printf("%d\n",d[F]);
	}
	return 0;
}
