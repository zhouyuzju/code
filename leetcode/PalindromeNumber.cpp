class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int l = 1;
        int k = x;
        while(k >= 10){
            l *= 10;
            k /= 10;
        }
        while(x >= 10){
            if(x % 10 != x / l)
                return false;
            x  = (x % l) / 10;
            l /= 100;
        }
        return true;
    }
};

