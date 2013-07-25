class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0 || postorder.size() == 0 || inorder.size() != postorder.size())
            return NULL;
        return construct(inorder,postorder,0,postorder.size() - 1,postorder.size() - 1); 
    }
    TreeNode* construct(vector<int> &inorder,vector<int> &postorder,int start,int end,int postIndex){
        if(start == end){
            TreeNode* result = new TreeNode(inorder[end]);
            return result;
        }
        int rootValue = postorder[postIndex];
        int inorderIndex = -1;
        for(int i = 0;i < inorder.size();i++)
            if(inorder[i] == rootValue){
                inorderIndex = i;
                break;
            }
        TreeNode* root = new TreeNode(rootValue);
        if(inorderIndex > start)
            root->left = construct(inorder,postorder,start,inorderIndex - 1,postIndex - 1- (end - inorderIndex));
        if(inorderIndex < end)
            root->right = construct(inorder,postorder,inorderIndex + 1,end,postIndex - 1);
        return root;
    }
};

