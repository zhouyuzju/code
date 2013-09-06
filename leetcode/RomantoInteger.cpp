class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        if(s.size() == 0)
            return sum;
        map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        
        for(int i = 0;i < s.size();)
            if(i + 1 < s.size() && m[s[i]] < m[s[i + 1]]){
                sum += m[s[i + 1]] - m[s[i]];
                i += 2;
            }
            else{
                sum += m[s[i]];
                i += 1;
            }
        return sum;
    }
};

