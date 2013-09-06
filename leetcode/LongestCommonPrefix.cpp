class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0 || strs[0].size() == 0)
            return "";
        int n = strs.size();
        int len = strs[0].size();
        for(int i = 0;i < len;i++)
            for(int j = 1;j < n;j++)
                if(strs[0][i] != strs[j][i])
                    return strs[0].substr(0,i);
        return strs[0];
    }
};

