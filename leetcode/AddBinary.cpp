#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(),n = b.size();
        if(m == 0)
            return b;
        else if(n == 0)
            return a;
        int carry = 0;
        vector<char> reverse;
        string result;
        int idx = 0;
        int i,j;
        for(i = m - 1,j = n - 1;i >= 0 && j >= 0;i--,j--){
            if(a[i] == b[j]){
                reverse.push_back(carry + '0');
                if(a[i] == '1')
                    carry = 1;
                else
                    carry = 0;
            }
            else{
                if(carry == 1){
                    reverse.push_back('0');
                    carry = 1;
                }
                else{
                    reverse.push_back('1');
                    carry = 0;
                }
            }
        }
        for(int k = i;k >= 0;k--){
            if(a[k] == '1' && carry == 1){
                reverse.push_back('0');
                carry = 1;
            }
            else{
                reverse.push_back(a[k] + carry);
		carry = 0;
            }
        }
        for(int k = j;k >= 0;k--){
            if(b[k] == '1' && carry == 1){
                reverse.push_back('0');
                carry = 1;
            }
            else{
                reverse.push_back(b[k] + carry);
		carry = 0;
            }
        }
        if(carry == 1)
            reverse.push_back('1');
        int length = reverse.size() - 1;
        while(reverse[length] == '0') length--;
        while(length >= 0) result += reverse[length--];
        if(result == "")
            result = "0";
        return result;
    }
};

int main(){
	string a = "101111";
	string b = "10";
	Solution* s = new Solution();
	cout << s->addBinary(a,b) << endl;
	return 0;
}
