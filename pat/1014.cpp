#include <iostream>
#include <cstdio>
#include <queue>
#define MAXTIME 60 * 9
#define MAX 1 << 31 - 1
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

char* convert(int a){
	char* time = new char[6];
	int hh = a / 60 + 8;
	int mm = a % 60;
	sprintf(time,"%02d:%02d",hh,mm);
	return time;
}

int main(){
	int N,M,K,Q;
	scanf("%d%d%d%d",&N,&M,&K,&Q);
	queue<pair<int,int> > windows[N];
	int customer[K + 1];
	int finish[K + 1];
	int count[N];
	int cursor = 1;
	for(int i = 1;i <= K;i++){
		scanf("%d",&customer[i]);
		finish[i] = -1;
		int min = M + 1;
		int idx = -1;
		for(int j = 0;j < N;j++){
			count[j] = 0;
			if(min > windows[j].size()){
				min = windows[j].size();
				idx = j;
			}
		}
		if(idx != -1 && min < M){
			windows[idx].push(make_pair(customer[i],i));
			cursor++;
		}
	}
	/**
	for(int i = 0;i < N;i++){
		while(windows[i].size() > 0){
			pair<int,int> a = windows[i].front();
			printf("[%d,%d] ",a.first,a.second);
			windows[i].pop();
		}
		printf("\n");
	}*/
	while(true){
		int min = MAX;
		int idx = -1;
		for(int i = 0;i < N;i++)
			if(windows[i].size() > 0 && min > count[i] + windows[i].front().first){
				min = count[i] + windows[i].front().first;
				idx = i;
			}
		if(idx == -1)
			break;
		count[idx] += windows[idx].front().first;
		if(count[idx] - windows[idx].front().first < MAXTIME)
			finish[windows[idx].front().second] = count[idx];
		else
			finish[windows[idx].front().second] = MAX;
		windows[idx].pop();
		if(cursor <= K){
			windows[idx].push(make_pair(customer[cursor],cursor));
			cursor++;
		}
	}
	for(int i = 0;i < Q;i++){
		int query;
		scanf("%d",&query);
		if(finish[query] != MAX)
			printf("%s\n",convert(finish[query]));
		else
			printf("Sorry\n");
	}
	return 0;
}
