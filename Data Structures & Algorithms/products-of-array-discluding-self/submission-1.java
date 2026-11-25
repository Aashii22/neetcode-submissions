class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;

        int[] suffix = new int[n];
        suffix[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suffix[i]=nums[i]*suffix[i+1];
        }
        int prefix = 1;
        int[] ans = new int[n];
        for(int i=0; i<n-1; i++){
            ans[i] = prefix*suffix[i+1];
            prefix*=nums[i];
        }
        ans[n-1] = prefix;

        return ans;
    }
}  
