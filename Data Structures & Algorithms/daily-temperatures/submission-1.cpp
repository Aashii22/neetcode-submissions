class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        stack<int> stk;
        vector<int> ans(n);
        ans[n-1]=0;

        int i=0;
        while(i<n){
            while(!stk.empty() && temperatures[stk.top()]<temperatures[i]){
                ans[stk.top()]=(i-stk.top());
                stk.pop();
            }
            stk.push(i++);
        }
        return ans;
    }
};
