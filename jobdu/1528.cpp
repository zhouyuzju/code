#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
const int MAX = 500000;
char str[MAX];
char s[MAX];
int p[MAX];

int main(){
	while(scanf("%s",str) != EOF){
		int j = 0;
		s[j++] = '$';
		for(int i = 0;str[i];i++){
			s[j++] = '#';
			s[j++] = str[i];
		}
		s[j++] = '#';
		s[j] = '\0';
		int id = 0, mx = 0,maxVal = 0;
		p[0] = 0;
		for(int i = 1;i < j;i++){
			p[i] = mx > i ? min(p[2 * id - i],mx - i) : 1;
			while(s[i + p[i]] == s[i - p[i]])
				p[i]++;
			if(i + p[i] > mx){
				mx = i + p[i];
				id = i;
			}
			maxVal = max(maxVal,p[i]);
		}
		printf("%d\n",maxVal - 1);
	}
	return 0;
}
