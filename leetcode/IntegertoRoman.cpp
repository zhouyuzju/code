class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        if(num <= 0)
            return result;
        int number[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i = 0;
        while(num > 0){
            if(num >= number[i]){
                num -= number[i];
                result += roman[i];
            }
            else
                i++;
        }
        return result;
    }
};

