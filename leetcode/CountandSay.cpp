#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0)
            return "";
	else if(n == 1)
	    return "1";
        vector<int> digit(1,1);
        for(int i = 1;i < n;i++){
            vector<int> tmp;
            for(int j = 0;j < digit.size();j++){
                int num = digit[j];
                int cnt = 1;
                while(j + 1 < digit.size() && digit[j] == digit[j + 1]){
                    j++;
                    cnt++;
                }
                tmp.push_back(cnt);
                tmp.push_back(num);
            }
            digit.clear();
            for(int j = 0;j < tmp.size();j++)
                digit.push_back(tmp[j]);
        }
        string result;
        for(int i = 0;i < digit.size();i++)
            result += (char)(digit[i] + '0');
        return result;
    }
};
int main(){
	Solution* s = new Solution();
	cout << s->countAndSay(3) << endl;
	return 0;
}
