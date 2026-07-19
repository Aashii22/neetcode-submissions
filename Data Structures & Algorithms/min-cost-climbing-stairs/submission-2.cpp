class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        //vector<int> dp(n+2, INT_MAX);
        //dp[n+1]=dp[n]=0;
        for(int i=n-3; i>=0; i--){
            cost[i] += min(cost[i+1], cost[i+2]);
        }    
        return min(cost[0], cost[1]);
    }
};
