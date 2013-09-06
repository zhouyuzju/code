#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <set>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	int N;
	scanf("%d",&N);
	getchar();
	vector<int> astack;
	multiset<int> big,small;
	int mid;
	for(int i = 0;i < N;i++){
		char cmd[20];
		gets(cmd);
		if(strcmp(cmd,"Pop") == 0){
			if(astack.size() == 0)
				printf("Invalid\n");
			else{
				int num = astack[astack.size() - 1];
				printf("%d\n",num);
				astack.pop_back();
				if(small.size() == big.size()){
					if(small.find(num) != small.end()){
						small.erase(small.lower_bound(num));
						if(astack.size() > 0)
							mid = *(big.begin());
					}
					else{
						big.erase(big.lower_bound(num));
						if(astack.size() > 0)
							mid = *(small.rbegin());
					}
				}
				else if(small.size() > big.size()){
					if(small.find(num) != small.end()){
						small.erase(small.lower_bound(num));
						if(astack.size() > 0)
							mid = *(small.rbegin());
					}
					else{
						big.erase(big.lower_bound(num));
						int last = *(small.rbegin());
						small.erase(small.lower_bound(last));
						big.insert(last);
						if(astack.size() > 0)
							mid = *(small.rbegin());
					}
				}
				else{
					if(big.find(num) != big.end()){
						big.erase(big.lower_bound(num));
						if(astack.size() > 0)
							mid = *(small.rbegin());
					}
					else{
						small.erase(small.lower_bound(num));
						int first = *(big.begin());
						big.erase(big.lower_bound(first));
						small.insert(first);
						if(astack.size() > 0)
							mid = *(small.rbegin());
					}

				}
			}
		}
		else if(strcmp(cmd,"PeekMedian") == 0){
			if(astack.size() == 0)
				printf("Invalid\n");
			else{
				printf("%d\n",mid);
			}
		}
		else{
			int num = atoi(cmd + 5);
			if(astack.size() == 0){
				mid = num;
				small.insert(num);
			}
			else{
				if(small.size() > big.size()){
					if(num >= mid){
						big.insert(num);
						mid = *(small.rbegin());
					}
					else{
						small.insert(num);
						int last = *(small.rbegin());
						small.erase(small.lower_bound(last));
						big.insert(last);
						mid = *(small.rbegin());
					}
				}
				else if(small.size() == big.size()){
					if(num >= mid){
						big.insert(num);
						mid = *(big.begin());
					}
					else{
						small.insert(num);
						mid = *(small.rbegin());
					}
				}
				else{
					if(num >= mid){
						big.insert(num);
						int begin = *(big.begin());
						big.erase(big.lower_bound(begin));
						small.insert(begin);
						mid = *(small.rbegin());
					}
					else{
						small.insert(num);
						mid = *(small.rbegin());
					}
				}
			}
			astack.push_back(num);
		}
	}
	return 0;
}
