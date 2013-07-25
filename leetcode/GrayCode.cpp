class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        for(int i = 0;i < pow(2,n);i++)
            result.push_back(grayNum(i));
        return result;
    }
private:
    unsigned int grayNum(int n){
        return (n >> 1) ^ n;
    }
};

