class Solution {
public:
    int totalNQueens(int n) {
        int cnt = 0;
        if(n <= 0)
            return cnt;
        vector<int> board(n,-1);
        dfs(board,cnt,0,n);
        return cnt;
    }
private:
    void dfs(vector<int>& board, int& cnt, int l, int n){
        if(l == n){
           cnt++;
           return;
        }
        for(int i = 0;i < n;i++){
            bool valid = true;
            for(int j = 0;j < l;j++)
                if(i == board[j] || abs(board[j] - i) == l - j){
                    valid = false;
                    break;
                }
            if(valid){
                board[l] = i;
                dfs(board,cnt,l + 1,n);
            }
        }
    }
};

