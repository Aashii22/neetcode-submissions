class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int> > res;
        res.push_back({});

        int curr=0, prev=0;
        vector<int> tmp;
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1])
            curr = prev;
            else
            curr = 0;

            prev = res.size();
            for(int j=curr; j<prev; j++){
                tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }

        return res;
        
    }
};
