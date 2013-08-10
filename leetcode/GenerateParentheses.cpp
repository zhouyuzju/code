#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n <= 0)
            return result;
        string candidate = string(2 * n,' ');
        dfs(result,candidate,0,0,n);
    }
private:
    void dfs(vector<string>& result, string& candidate, int left, int right, int n){
        if(left == right && right == n){
            result.push_back(string(candidate));
            return;
        }
        if(left < n){
            candidate[left + right] = '(';
            dfs(result,candidate,left + 1,right,n);
            candidate[left + right] = ' ';
        }
        if(left > right){
            candidate[left + right] = ')';
            dfs(result,candidate,left,right + 1,n);
            candidate[left + right] = ' ';
        }
    }
};
int main(){
	Solution* s = new Solution();
	vector<string> result = s->generateParenthesis(2);
	for(int i = 0;i < result.size();i++)
		cout << result[i] << endl;
	return 0;
}
