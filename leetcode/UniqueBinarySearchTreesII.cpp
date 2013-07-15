class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return construct(1,n);        
    }
private:
    vector<TreeNode*> construct(int start, int end){
        vector<TreeNode *> result;
        if(start > end){
            result.push_back(NULL);
            return result;
        }
        
        for(int i = start;i <= end;i++){
            vector<TreeNode *> left = construct(start, i - 1);
            vector<TreeNode *> right = construct(i + 1,end);
            for(int j = 0;j < left.size();j++)
                for(int k = 0;k < right.size();k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    result.push_back(root);
                }
        }
        return result;
    }
};

