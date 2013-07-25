class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        if(root == NULL)
            return result;
        vector<int>* list;
        queue<pair<TreeNode*,int> > q;
        q.push(make_pair(root,0));
        int l = -1;
        while(q.size() > 0){
            pair<TreeNode*,int> p = q.front();
            q.pop();
            if(l < p.second){
                if(l != -1)
                    result.push_back(*list);
                l = p.second;
                list = new vector<int>();
                (*list).push_back(p.first->val);
            }
            else
                (*list).push_back(p.first->val);
            if(p.first->left)
                q.push(make_pair(p.first->left,p.second + 1));
            if(p.first->right)
                q.push(make_pair(p.first->right,p.second + 1));
        }
        result.push_back(*list);
        return result;
    }
};

