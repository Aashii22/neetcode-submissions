class Solution {
public:
    void swap(vector<int> &nums1, vector<int> &nums2){
        vector<int> tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            swap(nums1, nums2);
        }

        int m = nums1.size(), n = nums2.size();
        int half = (m+n+1)/2;

        int l=0, r=m, l1, l2, r1, r2, mid1, mid2;
        double ans = 0;
        while(l<=r){
            mid1 = (l+r)/2;

            mid2 = half - mid1;

            l1 = mid1>0 ? nums1[mid1-1] : INT_MIN;
            l2 = mid2>0 ? nums2[mid2-1] : INT_MIN;
            r1 = mid1<m ? nums1[mid1] : INT_MAX;
            r2 = mid2<n ? nums2[mid2] : INT_MAX;

            if(l1<=r2 && l2<=r1){
                if((m+n)%2==0){
                    ans = ((double)(max(l1, l2) + min(r1, r2)))/2;
                }
                else{
                    ans = max(l1, l2);
                }
                break;
            }
            else if(l1>r2){
                r = mid1-1;
            }
            else if(l2>r1){
                l = mid1+1;
            }
        }
        return ans;
    }
};
