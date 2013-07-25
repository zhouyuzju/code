class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > empty;
        if(root == NULL)
            return empty;
        vector<vector<int> > result;
        queue<pair<TreeNode*,int> > q;
        q.push(make_pair(root,0));
        vector<int> * list;
        int level = -1;
        while(q.size() > 0){
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            if(level < depth){
                if(level != -1){
                    if(level & 1 == 1){
                        vector<int> *tmp = new vector<int>();
                        for(int i = list->size() - 1;i >= 0;i--)
                            tmp->push_back((*list)[i]);
                        delete list;
                        result.push_back(*tmp);
                    }
                    else
                        result.push_back(*list);
                }
                list = new vector<int>();
                level = depth;
                list->push_back(node->val);
            }
            else
                list->push_back(node->val);
            if(node->left)
                q.push(make_pair(node->left,depth + 1));
            if(node->right)
                q.push(make_pair(node->right,depth + 1));
        }
        if(level & 1 == 1){
            vector<int> *tmp = new vector<int>();
            for(int i = list->size() - 1;i >= 0;i--)
                tmp->push_back((*list)[i]);
            delete list;
            result.push_back(*tmp);
        }
        else
            result.push_back(*list);
        return result;
    }
};

