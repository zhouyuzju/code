#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	for(int i = 0;i < T;i++){
		int m,n;
		scanf("%d%d",&m,&n);
		vector<pair<int,int> > c[m + 1];
		for(int j = 0;j < n;j++){
			int ts,te,tc;
			scanf("%d%d%d",&ts,&te,&tc);
			if(m >= te)
				c[te].push_back(make_pair(ts,tc));
		}
		int get[m + 1];
		get[0] = 0;
		for(int k = 1;k <= m;k++){
			int tmpmax = -1;
			for(int j = 0;j < c[k].size();j++)
				tmpmax = max(tmpmax,get[c[k][j].first - 1] + c[k][j].second);
			get[k] = max(get[k - 1], tmpmax);
		}
		printf("%d\n",get[m]);
	}

	return 0;
}
