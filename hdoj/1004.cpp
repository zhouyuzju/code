#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
int main(){
	int n;
	while(true){
		scanf("%d",&n);
		if(n == 0)
			break;
		map <string,int> get;
		for(int i = 0;i < n;i++){
			string color;
			cin >> color;
			get[color]++;
		}
		int num = -1;
		string result;
		for(map<string,int>::iterator it = get.begin();it != get.end();it++){
			if(num < it -> second){
				result = it -> first;
				num = it -> second;
			}
		}
		cout << result << endl;
	}
	return 0;
}
