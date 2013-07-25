class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        if(k > fact(n) || n <= 0 || k <= 0)
            return result;
        int kk = k - 1;
        vector<int> cnt(n,0);
        for(int i = n - 1;i >= 0;i--){
            while(kk >= fact(i)){
                cnt[i]++;
                kk -= fact(i);
            }
        }
        vector<int> sequence;
        for(int i = 1;i <= n;i++)
            sequence.push_back(i);
        for(int i = n - 1;i >= 0;i--){
            result += (char)(sequence[cnt[i]] + '0');
            sequence.erase(sequence.begin() + cnt[i]);
        }
        return result;
    }
private:
    int fact(int n){
        int result = 1;
        for(int i = 2;i <= n;i++)
            result *= i;
        return result;
    }
};

