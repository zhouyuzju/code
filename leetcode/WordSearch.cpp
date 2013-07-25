class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if(board.size() == 0 || board[0].size() == 0)
            return false;
        else if(word.size() == 0)
            return true;
        int m = board.size();
        int n = board[0].size();
        bool** visit = new bool* [m];
        for(int i = 0;i < m;i++)
            visit[i] = new bool[n];
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
                visit[i][j] = false;
        for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++){
                if(dfs(board,visit,word,i,j,1))
                    return true;
            }
        return false;
    }
private:
    bool dfs(vector<vector<char> > &board, bool** visit, string word, int i, int j, int l){
        if(!visit[i][j] && l == word.size() && board[i][j] == word[l - 1])
            return true;
        else if(board[i][j] != word[l - 1] || visit[i][j])
            return false;
        visit[i][j] = true;
        bool left = false, right = false, up = false, down = false;
        if(i > 0 && dfs(board,visit,word,i - 1,j,l + 1))
            return true;
        if(i < board.size() - 1 && dfs(board,visit,word,i + 1,j,l + 1))
            return true;
        if(j > 0 && dfs(board,visit,word,i,j - 1,l + 1))
            return true;
        if(j < board[0].size() - 1 && dfs(board,visit,word,i,j + 1,l + 1))
            return true;
        visit[i][j] = false;
        return false;
    }
};

