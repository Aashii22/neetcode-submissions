class Solution {
public:
    vector<int> dp;
    int dfs(vector<int> &cost, int curr){
        if(curr>=cost.size())
        return 0;

        if(dp[curr]!=-1)
        return dp[curr];

        return dp[curr] = cost[curr] + min(dfs(cost, curr+1), dfs(cost, curr+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        dp.resize(n, -1);

        return min(dfs(cost, 0), dfs(cost, 1));
    }
};
