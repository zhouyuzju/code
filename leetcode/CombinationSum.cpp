class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        if(candidates.size() == 0)
            return result;
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        dfs(result,candidates,path,target,0);
        return result;
    }
private:
    void dfs(vector<vector<int> >& result, vector<int>& candidates, vector<int>& path, int target, int sum){
        if(target == sum){
            vector<int> ans;
            for(int i = 0;i < path.size();i++)
                ans.push_back(path[i]);
            result.push_back(ans);
            return;
        }
        else if(target < sum)
            return;
        if(path.size() == 0){
            for(int i = 0;i < candidates.size();i++){
                    path.push_back(candidates[i]);
                    dfs(result,candidates,path,target,sum + candidates[i]);
                    path.pop_back();
                } 
        }
        else{
            for(int i = 0;i < candidates.size();i++)
                if(candidates[i] >= path[path.size() - 1]){
                    path.push_back(candidates[i]);
                    dfs(result,candidates,path,target,sum + candidates[i]);
                    path.pop_back();
                }
        }
    }
};

