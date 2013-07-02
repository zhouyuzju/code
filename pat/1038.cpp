#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define PR(x) cout << #x << " = " << x << endl
#define MAX 10
using namespace std;

bool mycmp(char *a, char* b){
	char ab[2 * MAX], ba[2 * MAX];
	strcpy(ab,a);
	strcat(ab,b);
	strcpy(ba,b);
	strcat(ba,a);
	if(strcmp(ab,ba) < 0)
		return true;
	else
		return false;
}

int main(){
	int N;
	scanf("%d",&N);
	char* num[N];
	for(int i = 0;i < N;i++){
		char* str = new char[MAX];
		scanf("%s",str);
		num[i] = str;
	}
	sort(num, num + N, mycmp);
	char min[MAX * N + 1];
	if(N == 0)
		return 0;
	strcpy(min,num[0]);
	for(int i = 1;i < N;i++)
		strcat(min,num[i]);
	bool flag = false;
	for(int i = 0;min[i] != '\0';i++){
		if(min[i] != '0')
			flag = true;
		if(flag || (!flag && min[i + 1] == '\0'))
			printf("%c",min[i]);
	}
	printf("\n");
	return 0;
}
