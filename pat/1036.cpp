#include <iostream>
#include <cstdio>
#define PR(x) cout << #x << " = " << x << endl
#define MAX 11
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	int fs = -1, ms = 101;
	char* fn;
	char* mn;
	char* fid;
	char* mid;
	
	for(int i = 0;i < N;i++){
		char* name = new char[MAX];
		char* ID = new char[MAX];
		char male;
		int grade;
		scanf("%s %c%s%d",name,&male,ID,&grade);
		//PR(name);PR(male);PR(ID);PR(grade);
		if(male == 'M' && ms > grade){
			mn = name;
			mid = ID;
			ms = grade;
		}
		else if(male == 'F' && fs < grade){
			fn = name;
			fid = ID;
			fs = grade;
		}
	}
	if(fs == -1)
		printf("Absent\n");
	else
		printf("%s %s\n",fn,fid);
	if(ms == 101)
		printf("Absent\n");
	else
		printf("%s %s\n",mn,mid);
	if(fs == -1 || ms == 101)
		printf("NA\n");
	else
		printf("%d\n",fs - ms);
	return 0;
}
