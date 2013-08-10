class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size() == 0){
            result.push_back("");
            return result;
        }
        vector<string> index(10,"");
        index[2] = "abc";
        index[3] = "def";
        index[4] = "ghi";
        index[5] = "jkl";
        index[6] = "mno";
        index[7] = "pqrs";
        index[8] = "tuv";
        index[9] = "wxyz";
        vector<int> path;
        dfs(result,index,path,digits);
    }
private:
    void dfs(vector<string>& result, vector<string>& index, vector<int>& path, string& digits){
        if(path.size() == digits.size()){
            string line;
            for(int i = 0;i < path.size();i++)
                line += (char)(index[digits[i] - '0'][path[i]]);
            result.push_back(line);
            return;
        }
        for(int i = 0;i < index[digits[path.size()] - '0'].size();i++){
            path.push_back(i);
            dfs(result,index,path,digits);
            path.pop_back();
        }
    }
};

