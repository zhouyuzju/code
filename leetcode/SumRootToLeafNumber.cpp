#include <iostream>
#include <cstdio>
using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    
    void dfs(TreeNode* root, int& sum,int v){
	if(!root)
		return;
	if(!root->left && !root->right)
		sum += v * 10 + root->val;
	if(root->left)
		dfs(root->left, sum, v * 10 + root->val);	

	if(root->right)
		dfs(root->right, sum, v * 10 + root->val);
    }
    
    int sumNumbers(TreeNode *root) {
        int sum = 0;
	if(!root)
		return 0;
	dfs(root,sum,0);
	return sum;
    }
};



int main(){
	Solution* s = new Solution();
	TreeNode* root = new TreeNode(1);
	TreeNode* left = new TreeNode(0);
	root->left = left;
	printf("%d\n",s->sumNumbers(root));
	return 0;
}
