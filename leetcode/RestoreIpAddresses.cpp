#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        if(s.size() == 0 || s.size() > 12)
            return result;
        string ip;
        dfs(result,s,ip,0,0);
        return result;
    }
private:
    void dfs(vector<string>& result, string s, string& ip, int start,int cnt){
    string max = "255";
        if(cnt == 4 && start == s.size()){
            string newString = string(ip);
            result.push_back(newString);
            return;
        }
        else if(cnt < 4 && start >= s.size())
            return;
        if(s[start] == '0'){
            if(cnt == 0)
                ip += s[start];
            else{
             	ip += '.';
		ip += s[start];
	    }
            dfs(result,s,ip,start + 1,cnt + 1);
            if(cnt == 0)
                ip = ip.substr(0,ip.size() - 1);
            else
                ip = ip.substr(0,ip.size() - 2);
            return;
        }
        for(int i = 1;i <= 3;i++){
	
	    if(start + i > s.size())
		    break;
	    else if(i == 3 && s.substr(start,i).compare(max) > 0)
		    break;
            if(cnt == 0)
                ip += s.substr(start,i);
            else{
             	ip += '.';
		ip += s.substr(start,i);
	    }
            dfs(result,s,ip,start + i,cnt + 1);
            if(cnt == 0)
                ip = ip.substr(0,ip.size() - i);
            else
                ip = ip.substr(0,ip.size() - i - 1);
        }
    }
};



int main(){
	Solution* s = new Solution();
	string ip = "9999999";
	vector<string> v = s->restoreIpAddresses(ip);
	for(int i = 0;i < v.size();i++)
		cout << v[i] << endl;
	return 0;
}
