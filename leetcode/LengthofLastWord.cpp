class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = 0;
        const char* c = s;
        while(*c){
            length++;
            c++;
        }
        if(length == 0)
            return 0;
        int idx = length - 1;
        int count = 0;
        while(idx >= 0){
            count = 0;
            while(idx >= 0 && s[idx] == ' ')
                idx--;
            while(idx >= 0 && s[idx] >= 'A' && s[idx] <= 'Z' || s[idx] >= 'a' && s[idx] <= 'z'){
                count++;
                idx--;
            }
            if(idx < 0 || s[idx] == ' ')
                return count;
            else
                while(idx >= 0 && s[idx] != ' ')
                    idx--;
        }
        return 0;
    }
};

