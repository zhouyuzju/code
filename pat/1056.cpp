#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
int main(){
	int Np,Ng;
	scanf("%d%d",&Np,&Ng);
	int rank[Np];
	int weight[Np];
	int order[Np];
	for(int i = 0;i < Np;i++)
		scanf("%d",&weight[i]);
	for(int i = 0;i < Np;i++)
		scanf("%d",&order[i]);
	int cnt,last = Np;
	int time = 0;
	while(last > 1){
		cnt = 0;
		int idx = 0;
		while(idx < last){
			vector<pair<int,int> >tmp;
			for(int i = 0;i < Ng && idx < last;i++,idx++)
				tmp.push_back(make_pair(weight[order[idx]],order[idx]));
			sort(tmp.begin(),tmp.end());
			for(int i = 0;i < tmp.size() - 1;i++)
				rank[tmp[i].second] = time;
			order[cnt++] = tmp[tmp.size() - 1].second;
			rank[tmp[tmp.size() - 1].second] = time + 1;
		}
		last = cnt;
		time++;
	}
	vector<pair<int,int> > tmp;
	for(int i = 0;i < Np;i++)
		tmp.push_back(make_pair(rank[i],i));
	sort(tmp.begin(),tmp.end());
	int r = 1,tt = tmp[tmp.size() - 1].first;

	for(int i = tmp.size() - 1;i >= 0;i--){
		if(tmp[i].first == tt)
			rank[tmp[i].second] = r;
		else{
			tt = tmp[i].first;
			r = tmp.size() - i;
			rank[tmp[i].second] = r;
		}
	}
	for(int i = 0;i < Np;i++)
		printf("%d%c",rank[i],i == Np - 1 ? '\n' : ' ');
	return 0;
}
