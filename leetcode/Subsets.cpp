class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        bool visit[S.size()];
        sort(S.begin(),S.end());
        for(int i = 0;i < S.size();i++)
            visit[i] = false;
        return backtrack(S,visit,0);
    }
private:
    vector<vector<int> > backtrack(vector<int> &S, bool* visit, int step){
        vector<vector<int> > result;
        if(step == S.size()){
            result.push_back(vector<int>());
            return result;
        }
        for(int i = 0;i < S.size();i++){
            if(!visit[i]){
                visit[i] = true;
                vector<vector<int> > tmp = backtrack(S,visit,step + 1);
                for(int j = 0;j < tmp.size();j++){
                    vector<int> in = tmp[j];
                    vector<int> ex = tmp[j];
                    in.push_back(S[i]);
                    sort(in.begin(),in.end());
                    sort(ex.begin(),ex.end());
                    result.push_back(in);
                    result.push_back(ex);
                }
            }
        }
        return result;
    }
};

