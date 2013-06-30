#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

bool startcmp(pair<string,pair<string,string> > a, pair<string,pair<string,string> > b){
	return a.second.first.compare(b.second.first) < 0;
}

bool endcmp(pair<string,pair<string,string> > a, pair<string,pair<string,string> > b){
	return a.second.second.compare(b.second.second) > 0;
}
int main(){
	int N;
	scanf("%d",&N);
	vector<pair<string,pair<string,string> > > log;
	for(int i = 0;i < N;i++){
		string id,start,end;
		cin >> id >> start >> end;
		log.push_back(make_pair(id,make_pair(start,end)));
	}
	string first,last;
	sort(log.begin(),log.end(),startcmp);
	first = log[0].first;
	sort(log.begin(),log.end(),endcmp);
	last = log[0].first;
	cout << first << " " << last << endl;
	return 0;
}
