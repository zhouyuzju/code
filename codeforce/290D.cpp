#include <cstdio>
using namespace std;
int main(){
	char s[51];
	scanf("%s",s);
	int n;
	scanf("%d",&n);
	for(int i = 0;s[i] != '\0';i++){
		if(s[i] >= 'A' && s[i] <= 'Z' && s[i] - 'A' >= n)
			s[i] = 'a' + s[i] - 'A';
		else if(s[i] >= 'a' && s[i] <= 'z' && s[i] - 'a' < n)
			s[i] = 'A' + s[i] - 'a';
	}
	printf("%s",s);
}
