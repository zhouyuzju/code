#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    void bfs(int i, int j, int m, int n, vector<vector<char> > &board){
	queue<pair<int,int> > aqueue;
    	if(board[i][j] == 'O'){
		aqueue.push(make_pair(i,j));
		board[i][j] = 'W';
	}
	while(aqueue.size() > 0){
		pair<int,int> point = aqueue.front();
		int x = point.first;
		int y = point.second;
		aqueue.pop();
		if(x - 1 > 0 && board[x - 1][y] == 'O'){
			board[x - 1][y] = 'W';
			aqueue.push(make_pair(x - 1,y));
		}
		if(x + 1 < m && board[x + 1][y] == 'O'){
			board[x + 1][y] = 'W';
			aqueue.push(make_pair(x + 1,y));
		}
		if(y - 1 > 0 && board[x][y - 1] == 'O'){
			board[x][y - 1] = 'W';
			aqueue.push(make_pair(x,y - 1));
		}
		if(y + 1 < n && board[x][y + 1] == 'O'){
			board[x][y + 1] = 'W';
			aqueue.push(make_pair(x,y + 1));
		}
	}
    }

    void solve(vector<vector<char> > &board) {
        int m = board.size();
        if(m <= 1)
            return;
        int n = board[0].size();
        if(n <= 1)
            return;
        for(int j = 0;j < n;j++){
		bfs(0,j,m,n,board);
		bfs(m - 1,j,m,n,board);
	}
	for(int i = 0;i < m;i++){
		bfs(i,0,m,n,board);
		bfs(i,n - 1,m,n,board);
	}
	for(int i = 0;i < m;i++)
            for(int j = 0;j < n;j++)
		if(board[i][j] == 'O')
			board[i][j] = 'X';
		else if(board[i][j] == 'W')
			board[i][j] = 'O';
        
    }
};


int main(){
	Solution* s = new Solution();
	char a[7][7] = {{'X','O','X','O','O','O','O'},{'X','O','O','O','O','O','O'},{'X','O','O','O','O','X','O'},{'O','O','O','O','X','O','X'},{'O','X','O','O','O','O','O'},{'O','O','O','O','O','O','O'},{'O','X','O','O','O','O','O'}};
	vector<vector<char> > v;
	for(int i = 0;i < 7;i++){
		vector<char> tmp;
		for(int j = 0;j < 7;j++)
			tmp.push_back(a[i][j]);
		v.push_back(tmp);
	}
	s->solve(v);
	for(int i = 0;i < 7;i++){
		for(int j = 0;j < 7;j++)
			printf("%c ",v[i][j]);
		printf("\n");
	}
	
	return 0;
}
