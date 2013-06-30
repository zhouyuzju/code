#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first * 1.0 / a.second > b.first * 1.0 / b.second;
}

int main(){
	int M,N;
	while(true){
		scanf("%d%d",&M,&N);
		if(M == -1 && N == -1)
			break;
		vector<pair<int,int> >bean;
		for(int i = 0;i < N;i++){
			int j,f;
			scanf("%d%d",&j,&f);
			bean.push_back(make_pair(j,f));
		}
		sort(bean.begin(),bean.end(),cmp);	
		double sum = 0.0;
		for(vector<pair<int,int> >::iterator it = bean.begin();it != bean.end() && M > 0;it++){
			if(M > (*it).second){
				sum += (*it).first;
				M -= (*it).second;
			}
			else{
				sum += M * 1.0 / (*it).second * (*it).first;
				break;
			}
		}
		printf("%.3f\n",sum);
	}
}
