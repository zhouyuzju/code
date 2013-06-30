#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string base2(int n){
	string result = "";
	for(int i = 0;i < n;i++)
		if(i % 2 == 0)
			result += 'a';
		else
			result += 'b';
	return result;
}

string last(int n){
	string result = "";
	for(int i = 0;i < n;i++)
		result += ('a' + i + 2);
	return result;
}

int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(n > 1 && k == 1 || n < k){
		printf("-1\n");
		return 0;
	}	
	else{
		if(n == 1)
			cout << "a" << endl;
		else if(k == 2)
			cout << base2(n) << endl;
		else
			cout << base2(n - (k - 2)) << last(k - 2) << endl;	
	}
	return 0;
}
