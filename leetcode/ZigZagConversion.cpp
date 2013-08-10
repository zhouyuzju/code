class Solution {
public:
    string convert(string s, int nRows) {
        vector<char> chars;
        if(s.size() == 0)
            return "";
        else if(nRows == 1)
            return s;
        int gap = nRows + nRows - 2;
        for(int i = 0;i < nRows;i++){
            int idx = i;
            while(idx < s.size()){
                chars.push_back(s[idx]);
                idx += gap;
                if(i > 0 && i < nRows - 1 && idx - i - i < s.size())
                    chars.push_back(s[idx - i - i]);
            }
        }
        return string(chars.begin(),chars.end());
    }
};

