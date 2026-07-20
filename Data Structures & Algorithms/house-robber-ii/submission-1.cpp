class Solution {
public:
    vector<int> dp;
    int solve(vector<int> &nums, int i, int j){

        dp[i] = 0;
        dp[i+1] = nums[i];

        for(int k=i+2;k<=j; k++){
            dp[k] = max(dp[k-1], nums[k-1]+dp[k-2]);
        }

        return dp[j];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
        return nums[0];
        
        dp.resize(n+1, 0);
        return max(solve(nums, 1, n), solve(nums, 0, n-1));
    }
};
