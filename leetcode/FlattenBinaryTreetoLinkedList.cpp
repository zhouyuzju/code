class Solution {
public:
    void flatten(TreeNode *root) {
        if(root == NULL)
            return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(left){
            root->right = left;
            root->left = NULL;
            TreeNode* node = root->right;
            while(node->right) node = node->right;
            node->right = right;
        }
        flatten(root->right);
    }
};

