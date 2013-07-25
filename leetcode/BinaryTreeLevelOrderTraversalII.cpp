class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        if(root == NULL)
            return result;
        int l = 0;
        level(root,l,0);
        vector<vector<int> > r(l);
        queue<pair<TreeNode*,int> > q;
        q.push(make_pair(root,1));
        while(q.size() > 0){
            pair<TreeNode*,int> p = q.front();
            q.pop();
            r[l - p.second].push_back(p.first->val);
            if(p.first->left)
                q.push(make_pair(p.first->left,p.second + 1));
            if(p.first->right)
                q.push(make_pair(p.first->right,p.second + 1));
        }
        return r;
    }
private:
    void level(TreeNode* root,int &l,int cur){
        if(root == NULL){
            l = max(l,cur);
            return;
        }
        level(root->left,l,cur + 1);
        level(root->right,l,cur + 1);
    }
};

