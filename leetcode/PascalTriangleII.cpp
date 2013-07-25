class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int last[rowIndex + 1];
        int cur[rowIndex + 1];
        for(int i = 0;i < rowIndex + 1;i++){
            last[i] = 0;
            cur[i] = 0;
        }
        
        for(int i = 1;i <= rowIndex + 1;i++){
            cur[0] = 1;
            cur[i - 1] = 1;
            for(int j = 1;j < i - 1;j++)
                cur[j] = last[j - 1] + last[j];
            for(int j = 0;j < i;j++)
                last[j] = cur[j];
        }
        vector<int> result;
        for(int i = 0;i < rowIndex + 1;i++)
            result.push_back(cur[i]);
        return result;
    }
};

