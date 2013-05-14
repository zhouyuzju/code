#include <cstdio>
#include <iostream>
#define PR(x) cout << #x << " = " << x <<endl
#define MAX 100001
using namespace std;
int main(){
	char l[MAX];
	gets(l);
	int i = 0;
	while(l[i] != '\0'){	
		while(l[i] == ' ')i++;
		if(l[i] == '"'){
			i++;
			printf("<");
			while(l[i] != '"')
				printf("%c",l[i++]);
			printf(">\n");
			i++;
		}
		else if(l[i] != '\0'){
			printf("<");
			while(l[i] != ' ' && l[i] != '\0')
				printf("%c",l[i++]);
			printf(">\n");
		}
	}
	return 0;
}
