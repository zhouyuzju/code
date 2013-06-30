/**
 * Combination of a c string.
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

void recursive(char* str,char* com,int length,int dest,int cur){
	if(dest == cur){
		com[cur] = '\0';
		printf("%s\n",com);
		return;
	}
	for(int i = 0;i < length;i++){
		bool flag = true;
		for(int j = 0;j < cur;j++)
			if(str[i] == com[j])
				flag = false;
		if(flag){
			com[cur] = str[i];
			recursive(str,com,length,dest,cur + 1);
		}
	}
}

void combination(char* str, int length){
	if(str == NULL || length <= 0)
		return;
	char* com = new char[length + 1];
	memset(com,'\0',length + 1);
	for(int i = 1;i <= length;i++)
		recursive(str,com,length,i,0);
	delete[] com;
}

int main(){
	char s[] = "abcef";
	combination(s,3);
	return 0;
}
