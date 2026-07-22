class Solution {
public:
    vector<vector<int> > ans;
    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    void solve(vector<int> &nums, int i, int n){
        if(i==n){
            ans.push_back(nums);
            return;
        }
        else{
            for(int j=i; j<n; j++){
                swap(nums[i], nums[j]);
                solve(nums, i+1, n);
                swap(nums[i], nums[j]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        vector<int> tmp;
        solve(nums, 0, n);
        return ans;
    }
};
