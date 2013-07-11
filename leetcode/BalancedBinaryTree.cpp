class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if(root == NULL)
            return true;
        if(abs(level(root->left,0) - level(root->right,0)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int level(TreeNode* root,int depth){
        if(root == NULL)
            return depth;
        return max(level(root->left,depth + 1),level(root->right,depth + 1));
    }
};

