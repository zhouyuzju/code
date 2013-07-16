class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        bool visit[S.size()];
        sort(S.begin(),S.end());
        for(int i = 0;i < S.size();i++)
            visit[i] = false;
        set<vector<int> > aset = backtrack(S,visit,0);
        vector<vector<int> > result;
        for(set<vector<int> >::iterator it = aset.begin();it != aset.end();it++)
            result.push_back(*it);
        return result;
    }
private:
    set<vector<int> > backtrack(vector<int> &S, bool* visit, int step){
        set<vector<int> > result;
        if(step == S.size()){
            result.insert(vector<int>());
            return result;
        }
        for(int i = 0;i < S.size();i++){
            if(!visit[i]){
                visit[i] = true;
                set<vector<int> > tmp = backtrack(S,visit,step + 1);
                for(set<vector<int> >::iterator it = tmp.begin();it != tmp.end();it++){
                    vector<int> in = (*it);
                    vector<int> ex = (*it);
                    in.push_back(S[i]);
                    sort(in.begin(),in.end());
                    sort(ex.begin(),ex.end());
                    result.insert(in);
                    result.insert(ex);
                }
            }
        }
        return result;
    }
};

