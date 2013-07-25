class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        vector<int> path;
        backtrack(root,sum,result,path);
        return result;
    }
private:
    void backtrack(TreeNode* root, int sum, vector<vector<int> > &result,vector<int> &path){
        if(root == NULL)
            return;
        path.push_back(root->val);
        if(root->left == NULL && root->right == NULL && sum == root->val){
            vector<int> newPath;
            for(int i = 0;i < path.size();i++)
                newPath.push_back(path[i]);;
            result.push_back(newPath);
        }
        if(root->left)
            backtrack(root->left,sum - root->val,result,path);
        if(root->right)
            backtrack(root->right,sum - root->val,result,path);
        path.pop_back();
    }
};

