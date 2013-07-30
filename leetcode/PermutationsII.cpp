#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() == 0)
            return result;
        vector<int> path;
        vector<bool> visit(num.size(),false);
        sort(num.begin(),num.end());
        dfs(result,path,visit,num);
        return result;
    }
private:
    void dfs(vector<vector<int> >& result, vector<int>& path, vector<bool>& visit, vector<int>& num){
        if(path.size() == num.size()){
            result.push_back(path);
            return;
        }
        for(int i = 0;i < num.size();i++){
            if(visit[i] || i > 0 && num[i] == num[i - 1] && visit[i - 1])
                continue;
            visit[i] = true;
            path.push_back(num[i]);
            dfs(result,path,visit,num);
            path.pop_back();
            visit[i] = false;
        }
    }
};

int main(){
	Solution* s = new Solution();
	vector<int> list;
	list.push_back(1);
	list.push_back(1);
	s->permuteUnique(list);
	return 0;
}
