class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> v;
        for(int x: nums){
            if(!v.empty()){
                if(v.back()<x)
                v.push_back(x);
                else if(v.back()>x)
                v[lower_bound(v.begin(), v.end(), x)-v.begin()]=x;
            }
            else
            v.push_back(x);
        }

        return v.size();
    }
};
