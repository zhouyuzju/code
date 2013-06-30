#include <iostream>
#include <cstdio>
#include <vector>
#define PR(x) cout << #x << " = " << x << endl
#define MAX 1 << 31 - 1
using namespace std;

int main(){
	int N,M,C1,C2;
	scanf("%d%d%d%d",&N,&M,&C1,&C2);
	int c[N];
	for(int i = 0;i < N;i++)
		scanf("%d",&c[i]);
	vector<pair<int,int> > map[N];
	for(int i = 0;i < M;i++){
		int c1,c2,l;
		scanf("%d%d%d",&c1,&c2,&l);
		map[c1].push_back(make_pair(c2,l));
		map[c2].push_back(make_pair(c1,l));
	}
	int carry[N];
	int d[N];
	bool visit[N];
	int count[N];
	for(int i = 0;i < N;i++){
		carry[i] = c[i];
		d[i] = MAX;
		visit[i] = false;
		count[i] = 0;
	}
	d[C1] = 0;
	count[C1] = 1;
	while(true){
		int min = MAX,idx = -1;
		for(int i = 0;i < N;i++)
			if(!visit[i] && min > d[i]){
				idx = i;
				min = d[i];
			}
		if(idx == -1)
			break;
		for(int i = 0;i < map[idx].size();i++){
			int cother = map[idx][i].first;
			int length = map[idx][i].second;
			if(d[cother] >= d[idx] + length){
				if(carry[cother] < carry[idx] + c[cother])
					carry[cother] = carry[idx] + c[cother];
				if(d[cother] > d[idx] + length)
					count[cother] = count[idx];
				else
					count[cother] += count[idx];
				d[cother] = d[idx] + length;

			}
		}
		visit[idx] = true;
	}
	printf("%d %d\n",count[C2],carry[C2]);
	return 0;
}
