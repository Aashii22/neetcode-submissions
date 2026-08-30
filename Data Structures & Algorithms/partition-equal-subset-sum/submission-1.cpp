class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum=0;

        for(auto &x: nums){
            sum+=x;
        }

        if(sum%2==1)
        return false;

        int target = sum/2;
        vector<bool> dp(target+1, false);
        vector<bool> nextDp(target+1, false);
        dp[0] = true;

        for(int i=0; i<n; i++){
            for(int j=1; j<=target; j++){
                if(nums[i]<=j){
                    nextDp[j] = dp[j] || dp[j-nums[i]];
                }
                else{
                    nextDp[j] = dp[j];
                }
            }
            swap(dp, nextDp);
        }

        return dp[target];
    }
};
