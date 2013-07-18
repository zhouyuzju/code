#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        if(s.size() == 0)
            return result;
        int length = 0, start = -1, end = -1;
        for(int i = 0;i < s.size();i++){
            int j = 0;
            for(j = 0;i + j < s.size() && i - j >= 0;j++)
                if(s[i + j] != s[i - j])
                    break;
            j--;
            if(length < 2 * j + 1){
                length = 2 * j + 1;
                start = i - j;end = i + j;
            }
            for(j = 0;i + j + 1 < s.size() && i -j >= 0;j++)
                if(s[i - j] != s[i + j + 1])
                    break;
            j--;
            if(length < 2 * j + 2){
                length = 2 * j + 2;
                start = i - j;end = i + j + 1;
            }
        }
        result = s.substr(start,end - start + 1);
        return result;
    }
};
int main(){
	string a = "abcdefghgfedjk";
	Solution* s = new Solution();
	cout << s->longestPalindrome(a) << endl;
	return 0;
}
