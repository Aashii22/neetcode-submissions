class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> stk;
        int ans = 0, idx, width;

        vector<int> left(n, -1);
        for(int i=0; i<n; i++){
            while(!stk.empty() && heights[stk.top()] > heights[i]){
                idx = stk.top();
                stk.pop();
                width = stk.empty() ? i : (i-stk.top()-1);
                ans = max(ans, heights[idx]*width);
            }
            stk.push(i);
        }

        while(!stk.empty()){
            idx = stk.top();
            stk.pop();
            width = stk.empty() ?  n : (n-stk.top()-1);
            ans = max(ans, heights[idx]*width);
        }

        return ans;
    }
};
