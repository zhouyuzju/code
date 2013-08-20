#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
struct record{
	int id;
	char* name;
	int score;
	record(int id,char* name,int score): id(id),name(name),score(score){}
};
bool cmp1(record* a, record* b){
	return a->id < b->id;
}

bool cmp2(record* a, record* b){
	if(strcmp(a->name,b->name) < 0)
		return true;
	else if(strcmp(a->name,b->name) == 0)
		return a->id < b->id;
	else
		return false;
}

bool cmp3(record* a, record* b){
	if(a->score < b->score)
		return true;
	else if(a->score == b->score)
		return a->id < b->id;
	else
		return false;
}

int main(){
	int N,C;
	scanf("%d%d",&N,&C);
	vector<record*> list;
	for(int i = 0;i < N;i++){
		int id;
		char* name = new char[9];
		int score;
		scanf("%d%s%d",&id,name,&score);
		record* r = new record(id,name,score);
		list.push_back(r);
	}
	if(C == 1)
		sort(list.begin(),list.end(),cmp1);
	else if(C == 2)
		sort(list.begin(),list.end(),cmp2);
	else if(C == 3)
		sort(list.begin(),list.end(),cmp3);
	for(int i = 0;i < list.size();i++)
		printf("%06d %s %d\n",list[i]->id,list[i]->name,list[i]->score);
	return 0;
}
