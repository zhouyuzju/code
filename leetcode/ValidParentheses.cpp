class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0)
            return true;
        stack<char> valid;
        for(int i = 0;i < s.size();i++)
            if(valid.size() == 0)
                valid.push(s[i]);
            else if(isPair(valid.top(),s[i]))
                valid.pop();
            else
                valid.push(s[i]);
        if(valid.size() == 0)
            return true;
        else
            return false;
    }
private:
    bool isPair(char a, char b){
        return a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}';
    }
};

