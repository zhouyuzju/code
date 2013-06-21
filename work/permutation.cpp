/**
 * Permutation of a c string.
 */
#include <iostream>
#include <cstdio>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

void swap(char* a, char* b){
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void permutation(char* str, char* begin){
	if(str == NULL)
		return;
	if(*begin == '\0'){
		printf("%s\n",str);
		return;
	}
	for(char* p = begin;*p != '\0';p++){
		swap(begin,p);
		permutation(str, begin + 1);
		swap(begin,p);
	}
}

int main(){
	char s[] = "aab";
	permutation(s,s);
	return 0;
}
