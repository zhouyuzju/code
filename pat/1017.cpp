#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

bool mycmp(pair<int,int> a, pair<int,int> b){
	return a.first < b.first;
}

struct cmp
{
    bool operator()(pair<int,int> a,pair<int,int> b){
    	return a.first > b.first;
    }
};

int main(){
	int N,K;
	scanf("%d%d",&N,&K);
	priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> window;
	vector<pair<int,int> > customer;
	for(int i = 0;i < N;i++){
		int hh,mm,ss,time,during;
		scanf("%d:%d:%d%d",&hh,&mm,&ss,&during);
		time = hh * 3600 + mm * 60 + ss;	
		if(time <= 17 * 3600)
			customer.push_back(make_pair(time,during > 60 ? 60 * 60 : during * 60));
	}
	sort(customer.begin(),customer.end(),mycmp);
	int idx = 0;
	for(idx = 0;idx < K && idx < customer.size();idx++)
		if(customer[idx].first < 8 * 3600){
			window.push(make_pair(8 * 3600 + customer[idx].second,idx));
		}
		else
			window.push(make_pair(customer[idx].first + customer[idx].second,idx));
	double sum = 0;
	int currentTime = 0;
	while(window.size() > 0){
		currentTime = window.top().first;
		int tmpIdx = window.top().second;
		int serveTime = currentTime - customer[tmpIdx].second;
		sum += (serveTime - customer[tmpIdx].first);
		window.pop();
		if(idx < customer.size()){
			window.push(make_pair(max(currentTime, customer[idx].first)+ customer[idx].second,idx));	
			idx++;
		}
	}
	if(customer.size() == 0)
		printf("0.0\n");
	else
		printf("%.1f\n",sum / 60.0 / customer.size());
	return 0;
}
