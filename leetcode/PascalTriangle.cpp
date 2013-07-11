class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > pascal;
        int last[numRows];
        int cur[numRows];
        for(int i = 0;i < numRows;i++){
            last[i] = 0;
            cur[i] = 0;
        }
        
        for(int i = 1;i <= numRows;i++){
            cur[0] = 1;
            if(i > 1)
                cur[i - 1] = 1;
            for(int j = 1;j < i - 1;j++)
                cur[j] = last[j - 1] + last[j];
            vector<int> newVector;
            for(int j = 0;j < i;j++){
                newVector.push_back(cur[j]);
                last[j] = cur[j];
            }
            pascal.push_back(newVector);
        }
        return pascal;
    }
};

