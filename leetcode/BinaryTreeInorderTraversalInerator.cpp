class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if(root == NULL)
            return result;
        stack<TreeNode*> s;
        TreeNode *current = root;
        bool done = false;
        while (!done) {
            if (current) {
                s.push(current);
                current = current->left;
            } else {
                if (s.empty()) {
                done = true;
                } else {
                    current = s.top();
                    s.pop();
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        }
    }
};

