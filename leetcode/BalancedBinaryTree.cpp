class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(root == NULL)
            return true;
        if(abs(level(root->left) - level(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int level(TreeNode* root){
        if(root == NULL)
            return 0;
        return max(level(root->left),level(root->right)) + 1;
    }
};

