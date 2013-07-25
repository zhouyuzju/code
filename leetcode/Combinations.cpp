class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        if(n == 0 || k == 0)
            return result;
        if(k >= n){
            vector<int> v;
            for(int i = 1;i <= n;i++)
                v.push_back(i);
            result.push_back(v);
            return result;
        }
        return dfs(n,k,k);
    }
private:
    vector<vector<int> > dfs(int n,int k,int l){
        vector<vector<int> > result;
        if(l == 0){
            result.push_back(vector<int>());
            return result;
        }
        vector<vector<int> > last = dfs(n,k,l - 1);
        for(int i = 0;i < last.size();i++){
            int j;
            if(last[0].size() == 0)
                j = 1;
            else
                j = last[i][last[0].size() - 1] + 1;
            for(;j <= n;j++){
                if(j + k - l <= n){
                    vector<int> tmp;
                    for(int t = 0;t < last[i].size();t++)
                        tmp.push_back(last[i][t]);
                    tmp.push_back(j);
                    result.push_back(tmp);
                }
            }
        }
        return result;
    }
};

