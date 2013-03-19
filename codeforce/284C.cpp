#include <iostream>
#include <cstdio>
#define N 200001
using namespace std;
int main(){
	int n,end = 1;
	int num[N] = {0};
	int b[N] = {0};
	long long sum = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		int type;
		cin >> type;
		if(type == 1){
			int aend,add;
			cin >> aend >> add;
			b[aend] += add;
			sum += (aend * add);
		}
		else if(type == 2){
			cin >> num[++end];
			sum += num[end];
		}
		else{
			//cout << sum << "," << end << "," << num[end] << "," << b[end] << endl;
			sum -= (num[end] + b[end]);
			b[end - 1] += b[end];
			b[end] = 0;
			end--;
		}
		printf("%.6f\n",sum * 1.0 / end);
	}
	return 0;
}
