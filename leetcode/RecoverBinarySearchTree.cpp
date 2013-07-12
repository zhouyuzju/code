#include <iostream>
#include <cstdio>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode *root) {
        dfs(root);
    }
private:
    void dfs(TreeNode* root){
        if(root == NULL)
            return;
        TreeNode* left = NULL;
        searchBig(root->left,root->val,left);
        TreeNode* right = NULL;
        searchSmall(root->right,root->val,right);
        if(left && right){
            int tmp = left->val;
            left->val = right->val;
            right->val = tmp;
        }
        else if(left && !right){
            int tmp = root->val;
            root->val = left->val;
            left->val = tmp;
        }
        else if(right && !left){
            int tmp = root->val;
            root->val = right->val;
            right->val = tmp;
        }
        else{
            dfs(root->left);
            dfs(root->right);
        }
    }
    
    void searchBig(TreeNode* root,int val,TreeNode* &big){
        if(root == NULL)
            return;
        if(big == NULL && root->val > val)
            big = root;
        else if(big != NULL && root->val > big->val)
            big = root;
        searchBig(root->left,val,big);
        searchBig(root->right,val,big);
    }
    
    void searchSmall(TreeNode* root,int val,TreeNode* &small){
        if(root == NULL)
            return;
        if(small == NULL && root->val < val)
            small = root;
        else if(small != NULL && root->val < small->val)
		    small = root;
        searchSmall(root->left,val,small);
        searchSmall(root->right,val,small);
    }
};

void test(TreeNode* node){
	if(node == NULL)
		return;
	printf("%d\n",node->val);
	test(node->left);
	test(node->right);
}

int main(){
	Solution* s = new Solution();
	TreeNode* root = new TreeNode(3);
	TreeNode* r = new TreeNode(1);
	TreeNode* rl = new TreeNode(2);
	root->right = r;
	r->left = rl;
	s->recoverTree(root);
	test(root);
}
