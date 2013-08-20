#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int powOfTen(int n){
	int result = 1;
	for(int i = 0;i < n;i++)
		result *= 10;
	return result;
}

int countOnes(char* str){
	if(str == NULL || *str == '\0' || *str < '0' || *str > '9')
		return 0;
	int first = *str - '0';
	int length = strlen(str);
	if(first == 0 && length == 1)
		return 0;
	else if(first > 0 && length == 1)
		return 1;
	int numFirst = 0,numOther,numRecursive;
	if(first == 1)
		numFirst = atoi(str + 1) + 1;
	else if(first > 1)
		numFirst = powOfTen(length - 1);
	numOther = first * (length - 1) * powOfTen(length - 2);
	numRecursive = countOnes(str + 1);
	return numFirst + numOther + numRecursive;
}

int main(){
	int n;
	scanf("%d",&n);
	char str[20];
	sprintf(str,"%d",n);
	printf("%d\n",countOnes(str));
	return 0;
}
