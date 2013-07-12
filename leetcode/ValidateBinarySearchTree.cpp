class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isBSTSub(root,INT_MIN,INT_MAX);
    }
    
    bool isBSTSub(TreeNode* root,int min,int max){
        if(root == NULL)
            return true;
        if(min < root->val && root->val < max)
            return isBSTSub(root->left,min,root->val) && isBSTSub(root->right,root->val,max);
        else
            return false;
    }
};

