/**
 * Count 1s between 1 to N
 */
#include <iostream>
#include <cstdio>
#include <exception>
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

int countOne(char* str){
	if(str == NULL || (*str) == '\0' || (*str) < '0' || (*str) > '9')
		return 0;
	int first = (*str) - '0';
	int length = strlen(str);
	if(length == 1 && first == 0)
		return 0;
	if(length == 1 && first > 0)
		return 1;
	int numFirst = 0;
	if(first > 1)
		numFirst = powOfTen(length - 1);
	else if(first == 1)
		numFirst = atoi(str + 1) + 1;
	int numOther = first * (length - 1) * powOfTen(length - 2);
	int numRecursive = countOne(str + 1);
	return numFirst + numOther + numRecursive;
}

int NumberOfOne(int num){
	if(num <= 0)
		throw new exception();
	char str[50];
	sprintf(str,"%d",num);
	return countOne(str);
}

int main(){
	for(int i = 1;i <= 21345;i++)
		printf("%d->%d\n",i,NumberOfOne(i));
	return 0;
}
