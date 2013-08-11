class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        if(n <= 0)
            return result;
        vector<int> board(n,-1);
        dfs(result,board,0,n);
    }
private:
    void dfs(vector<vector<string> >& result, vector<int>& board, int l, int n){
        if(l == n){
            vector<string> solution;
            for(int i = 0;i < n;i++){
                string line = string(n,'.');
                line[board[i]] = 'Q';
                solution.push_back(line);
            }
            result.push_back(solution);
        }
        vector<bool> valid(n,true);
        for(int i = 0;i < l;i++){
            valid[board[i]] = false;
            if(board[i] - l + i>= 0)
                valid[board[i] - l + i] = false;
            if(board[i] + l - i< n)
                valid[board[i] + l - i] = false;
            
        }
        for(int i = 0;i < n;i++)
            if(valid[i]){
                board[l] = i;
                dfs(result,board,l + 1,n);
                board[l] = -1;
            }
    }
};

