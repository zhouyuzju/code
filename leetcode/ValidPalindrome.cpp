#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;
        string newString;
        for(int i = 0;i < s.length();i++)
            if(s[i] >= 'A' && s[i] <= 'Z')
                newString += (char)(s[i] + 32);
            else if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
                newString += s[i];
        if(newString.length() == 0)
            return true;
        string reverseString = newString;
        for(int i = newString.length() - 1;i >= 0;i--)
            reverseString[newString.length() - 1 - i] = newString[i];
        for(int i = 0;i < newString.length();i++)
            if(newString[i] != reverseString[i])
                return false;
        return true;
    }
};

int main(){
	Solution* s = new Solution();
	printf("%d",s->isPalindrome("ab"));
	return 0;
}
