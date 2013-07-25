class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size() == 0 || inorder.size() == 0 || preorder.size() != inorder.size())
            return NULL;
        return construct(preorder,inorder,0,inorder.size() - 1,0);
    }
private:
    TreeNode* construct(vector<int> &preorder,vector<int> &inorder,int start,int end,int preorderIndex){
        if(start == end){
            TreeNode* root = new TreeNode(inorder[end]);
            return root;
        }
        int rootVal = preorder[preorderIndex];
        int inorderIndex = -1;
        for(int i = start;i <= end;i++)
            if(rootVal == inorder[i]){
                inorderIndex = i;
                break;
            }
        TreeNode* node = new TreeNode(rootVal);
        if(inorderIndex > start)
            node->left = construct(preorder,inorder,start,inorderIndex - 1,preorderIndex + 1);
        if(inorderIndex < end)
            node->right = construct(preorder,inorder,inorderIndex + 1,end,preorderIndex + 1 + (inorderIndex - start));
        return node;
    }
};

