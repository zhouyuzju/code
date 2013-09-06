class Solution {
public:
    int reverse(int x) {
        bool flag = (x >= 0);
        x = flag ? x : -x;
        vector<int> digit;
        while(x > 0){
            digit.push_back(x % 10);
            x /= 10;
        }
        int result = 0;
        for(int i = 0;i < digit.size();i++)
            result = result * 10 + digit[i];    //may overflow
        return flag ? result : -result;
    }
};

