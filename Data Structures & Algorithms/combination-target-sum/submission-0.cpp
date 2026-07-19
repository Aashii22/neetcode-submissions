class Solution {
public:
    void solve(vector<int> &nums, int idx, vector<vector<int> > &ans, vector<int> &tmp, int target){
        if(target==0){
            ans.push_back(tmp);
            return;
        }
        else if(idx==nums.size() || target<0)
        return;

        if(nums[idx]<=target){
            tmp.push_back(nums[idx]);
            solve(nums, idx, ans, tmp, target-nums[idx]);
            tmp.pop_back();
        }
        solve(nums, idx+1, ans, tmp, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<int> tmp;
        vector<vector<int> > ans;
        solve(nums, 0, ans, tmp, target);

        return ans;
    }
};
