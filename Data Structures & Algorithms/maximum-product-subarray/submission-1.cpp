class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int ans = nums[0], curr=nums[0];
        for(int i=1; i<n; i++){
            curr*=nums[i];

            ans = max(ans, curr);
            if(nums[i]==0)
            curr = 1;
        }

        curr = nums[n-1];
        ans = max(ans, curr);
        for(int i=n-2; i>=0; i--){
            curr*=nums[i];

            ans = max(ans, curr);
            if(nums[i]==0)
            curr = 1;
        }

        return ans;
    }
};
