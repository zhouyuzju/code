class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if(height.size() == 0)
            return 0;
        stack<int> s;
        int i = 0, m = 0;
        height.push_back(0);
        while(i < height.size()){
            if(s.empty() || height[s.top()] <= height[i])
                s.push(i++);
            else{
                int t = s.top();
                s.pop();
                m = max(m, height[t] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        return m;
    }
};

