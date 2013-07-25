class Solution {
public:
    string minWindow(string S, string T) {
        if(S.size() < T.size())
            return "";
        int needToFind[256] = {0};
        int hasFind[256] = {0};
        int count = 0;
        for(int i = 0;i < T.size();i++)
            needToFind[T[i]]++;
        int i,j,minLen = INT_MAX,start = 0,end = S.size() - 1;
        for(i = 0,j = 0;j < S.size();j++){
            if(needToFind[S[j]] == 0) continue;
            hasFind[S[j]]++;
            if(hasFind[S[j]] <= needToFind[S[j]])
                count++;
            if(count == T.size()){
                while(needToFind[S[i]] == 0 || hasFind[S[i]] > needToFind[S[i]]){
                    if(hasFind[S[i]] > needToFind[S[i]])
                        hasFind[S[i]]--;
                    i++;
                }
                int len = j - i + 1;
                if(len < minLen){
                    minLen = len;
                    start = i;
                    end = j;
                }
            }
        }
        if(count != T.size())
            return "";
        else
            return S.substr(start,minLen);
    }
};

