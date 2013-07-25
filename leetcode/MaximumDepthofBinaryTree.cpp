class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0;
        level(root,l,0);
        return l;
    }
private:
    void level(TreeNode* root, int& l, int cur){
        if(root == NULL){
            l = max(l,cur);
            return;
        }
        level(root->left,l,cur + 1);
        level(root->right,l,cur + 1);
    }
};

