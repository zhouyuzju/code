#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int maxValue = INT_MIN;
        dfs(root,maxValue);
        return maxValue;
    }
private:
    int dfs(TreeNode* root,int& maxValue){
        if(root == NULL)
            return 0;
        int lv = dfs(root->left,maxValue);
        int rv = dfs(root->right,maxValue);
        int cv = max(root->val,max(lv + root->val,rv + root->val));
        maxValue = max(maxValue,max(cv,lv + rv + root->val));
        return cv;
    }
};

int main(){
	TreeNode * root = new TreeNode(1);
	Solution* s = new Solution();
	printf("%d\n",s->maxPathSum(root));
	return 0;
}
