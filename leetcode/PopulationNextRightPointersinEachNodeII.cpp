class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        queue<pair<TreeLinkNode*,int> > q;
        q.push(make_pair(root,0));
        while(q.size() > 0){
            pair<TreeLinkNode*,int> now = q.front();
            q.pop();
            if(q.size() == 0)
                now.first->next = NULL;
            else if(now.second != q.front().second)
                now.first->next = NULL;
            else
                now.first->next = q.front().first;
            if(now.first->left)
                q.push(make_pair(now.first->left,now.second + 1));
            if(now.first->right)
                q.push(make_pair(now.first->right,now.second + 1));
        }
    }
};

