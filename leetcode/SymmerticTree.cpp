class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL)
            return true;
        return isSymmertic(root->left,root->right);
    }
private:
    bool isSymmertic(TreeNode* left, TreeNode* right){
        if(left == NULL && right == NULL)
            return true;
        else if(left == NULL && right != NULL)
            return false;
        else if(right == NULL && left != NULL)
            return false;
        return left->val == right->val && isSymmertic(left->left,right->right) && isSymmertic(left->right,right->left);
    }
};

