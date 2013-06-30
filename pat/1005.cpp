#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#define PR(x) cout << #x << " = " << x << endl
#define MAX 101
using namespace std;

char words[10][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
	char N[MAX];
	vector<int> digits;
	scanf("%s",N);
	int count = 0;
	for(int i = 0;i < MAX && N[i] != '\0';i++)
		count += N[i] - '0';
	if(count == 0){
		printf("%s\n",words[0]);
	}
	else{
		while(count > 0){
			digits.push_back(count % 10);
			count /= 10;
		}
		for(int i = digits.size() - 1;i >= 0;i--)
			printf("%s%c",words[digits[i]],i == 0 ? '\n' : ' ');
	}
	return 0;
}
