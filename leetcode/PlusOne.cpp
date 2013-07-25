class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> reverse;
        vector<int> result;
        if(digits.size() == 0){
            result.push_back(1);
            return result;
        }
        int carry = 1;
        for(int i = digits.size() - 1;i >= 0;i--){
            reverse.push_back((digits[i] + carry) % 10);
            carry = (digits[i] + carry) / 10;
        }
        if(carry == 1)
            reverse.push_back(carry);
        for(int i = reverse.size() - 1;i >= 0;i--)
            result.push_back(reverse[i]);
        return result;
    }
};

