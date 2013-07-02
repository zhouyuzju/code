#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 5
using namespace std;

bool mycmp(char* a,char* b){
	if(strcmp(a,b) < 0)
		return true;
	else
		return false;
}

int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	vector<char*> school[K + 1];
	for(int i = 0;i < N;i++)
	{
		char* name = new char[MAX];
		scanf("%s",name);
		int courseNum;
		scanf("%d",&courseNum);
		for(int j = 0;j < courseNum;j++)
		{
			int courseNo;
			scanf("%d",&courseNo);
			school[courseNo].push_back(name);
		}
	}
	for(int i = 1;i <= K;i++)
	{
		printf("%d %d\n",i,school[i].size());
		sort(school[i].begin(),school[i].end(),mycmp);
		vector<char*>::iterator it = school[i].begin();
		for(;it != school[i].end();it++)
			printf("%s\n",(*it));
	}
	return 0;
}
