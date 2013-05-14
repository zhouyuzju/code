#include <cstdio>
#include <iostream>
#define MAX 1001
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
int main(){
	char a[MAX],b[MAX];
	gets(a);
	gets(b);
	int ca = 0,cb = 0;
	for(int i = 0;a[i] != '\0';i++)
		if(a[i] == '1')
			ca++;
	for(int i = 0;b[i] != '\0';i++)
		if(b[i] == '1')
			cb++;
	if(ca % 2 == 1)
		ca++;
	if(ca < cb)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
