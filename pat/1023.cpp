#include <iostream>
#include <cstdio>
#include <vector>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	int cnt[10] = {0};
	string num;
	cin >> num;
	vector<int> digit,dd;
	for(int i = 0;i < num.size();i++){
		cnt[num[i] - '0']++;
		digit.push_back(num[i] - '0');
	}
	int carry = 0;
	for(int i = num.size() - 1;i >= 0;i--){
		int sum = (num[i] - '0') * 2 + carry;
		int d = sum % 10;
		carry = sum / 10;
		dd.push_back(d);
	}
	if(carry != 0)
		dd.push_back(1);
	for(int i = 0;i < dd.size();i++)
		cnt[dd[i]]--;
	bool result = true;
	for(int i = 0;i < 10;i++)
		if(cnt[i] != 0){
			result = false;
			break;
		}
	if(result)
		printf("Yes\n");
	else
	printf("No\n");
	for(int i = dd.size() - 1;i >= 0;i--)
		printf("%d",dd[i]);
	printf("\n");
	return 0;
}
