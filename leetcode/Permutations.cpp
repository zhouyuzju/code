class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size() == 0)
            return result;
        bool mark[num.size()];
        for(int i = 0;i < num.size();i++)
            mark[i] = false;
        vector<int> sample;
        dfs(result,num,mark,sample,0);
        return result;
    }
private:
    void dfs(vector<vector<int> >& result, vector<int>& num, bool* mark, vector<int>& sample, int step){
        if(step == num.size()){
            vector<int> line;
            for(int i = 0;i < sample.size();i++)
                line.push_back(sample[i]);
            result.push_back(line);
        }
        for(int i = 0;i < num.size();i++){
            if(!mark[i]){
                mark[i] = true;
                sample.push_back(num[i]);
                dfs(result,num,mark,sample,step + 1);
                sample.pop_back();
                mark[i] = false;
            }
        }
    }

};

