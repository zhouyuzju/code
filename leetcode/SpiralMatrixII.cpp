#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > result;
        if(n == 0)
            return result;
        for(int i = 0;i < n;i++){
            vector<int> line(n,0);
            result.push_back(line);
        }
        int cnt = 1;
        for(int i = 0;i < (n + 1) / 2;i++){
            fill(result,cnt,(n - 1) * n,i,n);
        }
        return result;
    }
private:
    void fill(vector<vector<int> >& result,int& cnt,int size,int l,int n){
        for(int i = l;i < n - l;i++)
            result[l][i] = cnt++;
        for(int i = l + 1;i < n - l;i++)
	    result[i][n - 1 - l] = cnt++;
        for(int i = n - 2 - l;i >= l;i--)
            result[n - 1 - l][i] = cnt++;
        for(int i = n - 2 - l;i > l;i--)
            result[i][l] = cnt++;
    }
};
int main(){
	int n = 3;
	Solution* s = new Solution();
	vector<vector<int> > result = s->generateMatrix(n);
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++)
			printf("%d ",result[i][j]);
		printf("\n");
	}
	return 0;
}
