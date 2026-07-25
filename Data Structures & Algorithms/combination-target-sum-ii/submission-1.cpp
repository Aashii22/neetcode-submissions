class Solution {
public:
    vector<vector<int> > ans;
    void solve(vector<int> &nums, int idx, int target, vector<int> &tmp){
        if(target==0){
            ans.push_back(tmp);
            return;
        }
        else if(idx == nums.size() || target < 0)
        return;

        if(nums[idx]<=target){
            tmp.push_back(nums[idx]);
            solve(nums, idx+1, target-nums[idx], tmp);
            tmp.pop_back();
        }
        while(idx+1<nums.size() && nums[idx]==nums[idx+1])
        idx++;

        solve(nums, idx+1, target, tmp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        vector<int> tmp;

        solve(candidates, 0, target, tmp);
        return ans;
    }
};
