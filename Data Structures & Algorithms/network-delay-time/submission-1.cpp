class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dp(n+1, INT_MAX);
        dp[k] = 0;

        for(int i=0; i<n; i++){
            for(auto &x: times){
                if(dp[x[0]]!=INT_MAX)
                dp[x[1]] = min(dp[x[1]], dp[x[0]]+x[2]);

                //cout<<x[1]<<" "<<dp[x[1]]<<endl;
            }
        }

        int ans = *max_element(dp.begin()+1, dp.end());
        return ans==INT_MAX ? -1 : ans;
    }
};
