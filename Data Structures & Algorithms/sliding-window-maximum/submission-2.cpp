class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;
        int i=0, j=0;
        vector<int> ans;
        while(i<n){

            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            if(dq.front()<j)
            dq.pop_front();

            i++;

            if(i>=k){
                ans.push_back(nums[dq.front()]);
                j++;
            }
        }

        return ans;
    }
};
