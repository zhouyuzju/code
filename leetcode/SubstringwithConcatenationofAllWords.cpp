class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> result;
        if(L.size() == 0)
            return result;
        unordered_map<string,int> words;
        unordered_map<string,int> count;
        int wordNum = L.size();
        int wordSize = L[0].size();
        if(S.size() < wordSize * wordNum)
            return result;
        for(int i = 0;i < wordNum;i++)
            words[L[i]]++;
        for(int i = 0;i <= S.size() - wordSize * wordNum;i++){
            count.clear();
            int cnt = 0;
            for(;cnt < wordNum;cnt++){
                string word = S.substr(i + cnt * wordSize, wordSize);
                if(words.find(word) == words.end())
                    break;
                count[word]++;
                if(count[word] > words[word])
                    break;
            }
            if(cnt == wordNum)
                result.push_back(i);
        }
        return result;
    }
};

