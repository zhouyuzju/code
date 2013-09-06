#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
struct Rank{
	string id;
	int score;
	int finalRank;
	int locationNum;
	int localRank;
	Rank(string id,int s,int fr,int ln,int lr) : id(id),score(s),finalRank(fr),locationNum(ln),localRank(lr){}
};

bool great(pair<int,string> a,pair<int,string> b){
	return a.first > b.first;
}

bool great2(Rank* a, Rank* b){
	if(a->score > b->score)
		return true;
	else if(a->score == b->score){
		return a->id < b->id;
	}
	else
		return false;
}

int main(){
	int N;
	scanf("%d",&N);
	vector<Rank*> all;
	for(int i = 0;i < N;i++){
		int K;
		scanf("%d",&K);
		vector<pair<int,string> > local;
		for(int j = 0;j < K;j++){
			string id;
			int score;
			cin >> id >> score;
			local.push_back(make_pair(score,id));
		}
		sort(local.begin(),local.end(),great);
		int idx = 1;
		int score = local[0].first;
		for(int j = 0;j < K;j++){
			Rank* r;
			if(local[j].first != score){
				idx = j + 1;
				score = local[j].first;
			}
			r = new Rank(local[j].second,local[j].first,-1,i + 1,idx);
			all.push_back(r);
		}
	}
	sort(all.begin(),all.end(),great2);
	printf("%d\n",all.size());
	int idx = 1;
	int score = all[0]->score;
	for(int i = 0;i < all.size();i++){
		if(all[i]->score != score){
			idx = i + 1;
			score = all[i]->score;
		}
		cout << all[i]->id << " " << idx << " " << all[i]->locationNum << " " << all[i]->localRank << endl;
	}
	return 0;
}
