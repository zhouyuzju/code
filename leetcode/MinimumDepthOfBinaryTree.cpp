class Solution {
public:
    int minDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
        queue<pair<TreeNode*,int> > q;
        q.push(make_pair(root,1));
        int depth;
        while(q.size() > 0){
            pair<TreeNode*,int> p = q.front();
            q.pop();
            if(p.first->left == NULL && p.first->right == NULL){
                depth = p.second;
                break;
            }
            if(p.first->left)
                q.push(make_pair(p.first->left,p.second + 1));
            if(p.first->right)
                q.push(make_pair(p.first->right,p.second + 1));
        }
        return depth;
    }
};

