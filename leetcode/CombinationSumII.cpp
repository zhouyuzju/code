class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
        if(num.size() == 0)
            return result;
        vector<int> path;
        map<int,int> cnt;
        for(int i = 0;i < num.size();i++)
            cnt[num[i]]++;
        vector<int> numUnique;
        for(map<int,int>::iterator it = cnt.begin();it != cnt.end();it++)
            numUnique.push_back(it->first);
        sort(numUnique.begin(),numUnique.end());
        dfs(result,numUnique,path,cnt,target,0);
        return result;
    }
private:
    void dfs(vector<vector<int> >& result, vector<int>& num, vector<int>& path, map<int,int>& cnt, int target, int sum){
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
            for(int i = 0;i < num.size();i++){
                cnt[num[i]]--;
                path.push_back(num[i]);
                dfs(result,num,path,cnt,target,sum + num[i]);
                path.pop_back();
                cnt[num[i]]++;
            }
        }
        else{
            for(int i = 0;i < num.size();i++)
                if(cnt[num[i]] > 0 && num[i] >= path[path.size() - 1]){
                    cnt[num[i]]--;
                    path.push_back(num[i]);
                    dfs(result,num,path,cnt,target,sum + num[i]);
                    path.pop_back();
                    cnt[num[i]]++;
                }
        }
    }
};

