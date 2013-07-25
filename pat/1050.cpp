#include <iostream>
#include <cstdio>
#define PR(x) cout << #x << " = " << x << endl
#define N 256
#define MAX 10001
using namespace std;

int main(){
	char s1[MAX],s2[MAX];
	gets(s1);
	gets(s2);
	bool exist[N] = {0};
	for(int i = 0;s2[i] != '\0';i++)
		exist[s2[i]] = true;
	char* l = s1;
	char* m = s1;
	while((*l) != '\0'){
		if(!exist[(*l)]){
			*m = *l;
			m++;
		}
		l++;
	}
	*m = '\0';
	puts(s1);
	return 0;
}
