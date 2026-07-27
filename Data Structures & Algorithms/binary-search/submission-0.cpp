class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        int l=0, r=n-1, mid;
        while(l<=r){
            mid = l + (r-l)/2;

            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target)
            r--;
            else
            l++;
        }


        return -1;
    }
};
