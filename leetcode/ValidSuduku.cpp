class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<vector<bool> > rows(9,vector<bool>(9,false));
        vector<vector<bool> > columns(9,vector<bool>(9,false));
        vector<vector<bool> > blocks(9,vector<bool>(9,false));
        for(int i = 0;i < 9;i++)
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.')
                    continue;
                int c = board[i][j] - '1';
                if(rows[i][c] || columns[j][c] || blocks[i / 3 * 3 + j / 3][c])
                    return false;
                rows[i][c] = columns[j][c] = blocks[i / 3 * 3 + j / 3][c] = true;
            }
        return true;
    }
};

