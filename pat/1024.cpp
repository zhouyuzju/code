#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

bool isPalind(string str){
	int length = str.size();
	if(length % 2 == 0){
		int a1 = length / 2 - 1;
		int a2 = a1 + 1;
		for(;a1 >= 0 && a2 < length;a1--,a2++)
			if(str[a1] != str[a2])
				return false;
		return true;
	}
	else{
		int mid = length / 2;
		for(int i = 1;i <= mid;i++)
			if(str[mid - i] != str[mid + i])
				return false;
		return true;
	}
}

string addReverse(string str){
	int l = str.size();
	string other = string(l,0);
	for(int i = 0;i < l;i++)
		other[l - i - 1] = str[i];
	vector<int> digits;
	int carry = 0;
	for(int i = l - 1;i >= 0;i--){
		int sum = str[i] - '0' + other[i] - '0' + carry;
		int digit = sum % 10;
		carry = sum / 10;
		digits.push_back(digit);
	}
	if(carry)
		digits.push_back(carry);
	int idx = digits.size() - 1;
	while(digits[idx] == 0 && idx >= 0)
		idx--;
	string result;
	while(idx >= 0){
		result += digits[idx] + '0';
		idx--;
	}
	return result;
}

string removeZero(string str){
	string result;
	int i = 0;
	while(str[i] == '0' && i < str.size())
		i++;
	while(i < str.size())
		result += str[i++];
	return result;
}

int main(){
	string N;
	int K;
	cin >> N >> K;
	int step = 0;
	N = removeZero(N);
	while(true){
		if(isPalind(N)){
			cout << N << endl << step << endl;
			break;
		}
		if(step == K){
			cout << N << endl << step << endl;
			break;
		}
		N = addReverse(N);
		step++;
	}	
	return 0;
}
