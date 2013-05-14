/**
 *find the maximun continue substring length of a given string, all the char *acter in the substring should be different
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int findmax(char *str,int length){
	if(str == NULL)
		return 0;
	int max = 0,cur = 0,last = 0;
	int v[256];
	memset(v,-1,256 * sizeof(int));
	for(int i = 0;i < length;i++){
		if(v[str[i]] == -1){
			cur++;
			v[str[i]] = i;
		}
		else{
			if(last <= v[str[i]]){
				cur = i - v[str[i]];
				last = v[str[i]] + 1;
				v[str[i]] = i;
			}
			else{
				cur++;
				v[str[i]] = i;
			}
		}
		if(cur > max)
			max = cur;
	}
	return max;
}

int main(){
	char s[10] = "abcdecbag";
	printf("%d",findmax(s,9));
	return 0;
}
