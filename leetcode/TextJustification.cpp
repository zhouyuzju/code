class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        if(words.size() == 0 || L < 0)
            return result;
        int start = 0,end;
        while(start < words.size()){
            int length = words[start].size();
            int end = start + 1;
            int charsize = words[start].size();
            string line = "";
            while(length < L && end < words.size()){
                length += words[end].size() + 1;
                if(length <= L){
                    charsize += words[end].size();
                    end++;
                }
            }
            end--;
            if(end > start && end != words.size() - 1){
                int whiteNum = end - start;
                int space[whiteNum + 1];
                space[0] = 0;
                int per = (L - charsize) / whiteNum;
                int rest = L - charsize - per * whiteNum;
                for(int i = 1;i <= whiteNum;i++){
                    if(rest > 0)
                        space[i] = per + 1;
                    else
                        space[i] = per;
                    rest--;
                }
                for(int i = 0;i <= whiteNum;i++)
                    line += string(space[i],' ') + words[start + i];
            }
            else if(start == end)
                line += words[end] + string(L - charsize,' ');
            else{
                for(int i = 0;i <= end - start;i++)
                    line += words[start + i] + " ";
                int n = line.size();
                for(int i = n;i < L;i++)
                    line += " ";
            }
            result.push_back(line);
            start = end + 1;
        }
        return result;
    }
};

