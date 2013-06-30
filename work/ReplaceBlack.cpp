/**
 * Replace ' ' character in the given string with "%20"
 */
#include <cstdio>
#include <iostream>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

void replace(char * str){
	if(str == NULL)
		return;
	char * p = str - 1;
	int length = 0,blanknum = 0;
	while(true){
		length++;
		if((*str) == '\0')
			break;
		else if((*str) == ' ')
			blanknum++;
		str++;
	}
	char * p1 = str;
	char * p2 = str + 2 * blanknum;
	while(true){
		if(p1 == p)
			break;
		else if((*p1) != ' '){
			(*p2) = (*p1);
			p1--;
			p2--;
		}
		else{
			(*p2) = '0';p2--;
			(*p2) = '2';p2--;
			(*p2) = '%';p2--;
			p1--;
		}
	}
}

int main(){
	char str1[] = "Hello World Goodbye!";
	char* str2 = NULL;
	char str3[] = "ssl";
	replace(str3);
	PR(str3);
	return 0;
}
