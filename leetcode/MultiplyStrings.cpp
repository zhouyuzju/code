#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";
        int m = num1.size(), n = num2.size();
        string result;
        vector<int> d(m + n,0);
        vector<int> reverse;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                d[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        for(int i = m + n - 1;i >= 1;i--){
            if(d[i] > 9)
                d[i - 1] += d[i] / 10;
            reverse.push_back(d[i] % 10);
        }
        reverse.push_back(d[0] % 10);
        int idx = reverse.size() - 1;
        while(idx >= 0 && reverse[idx] == 0)
            idx--;
        while(idx < reverse.size())
            result += reverse[idx--] + '0';
        return result;
    }
};

int main(){
	Solution* s = new Solution();
	cout << s-> multiply("6","501") << endl;
	return 0;
}

