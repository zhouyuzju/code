class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0)
            return 0;
        stack<pair<char,int> > check;
        vector<bool> mark(s.size(),false);
        for(int i = 0;i < s.size();i++)
            if(check.size() == 0)
                check.push(make_pair(s[i],i));
            else{
                if(check.top().first == '(' && s[i] == ')'){
                    mark[check.top().second] = true;
                    mark[i] = true;
                    check.pop();
                }
                else
                    check.push(make_pair(s[i],i));
            }
        int cnt = 0,result = 0;
        for(int i = 0;i < s.size();i++)
            if(mark[i])
                cnt++;
            else{
                if(result < cnt)
                    result = cnt;
                cnt = 0;
            }
        if(result < cnt)
            result = cnt;
        return result;
    }
};

