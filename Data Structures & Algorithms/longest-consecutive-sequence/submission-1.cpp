class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int x: nums){
            mp[x]=1;
        }

        int curr, ans=0;
        for(int x: nums){
            curr = x;
            while(mp.find(curr+1)!=mp.end()){
                curr++;
            }
            ans = max(ans, curr-x+1);
        }

        return ans;
    }
};
