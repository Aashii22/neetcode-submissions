class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;

        int ans=0;
        for(int x: nums){
            if(!mp[x]){
                mp[x] = mp[x-1]+mp[x+1]+1;

                mp[x-mp[x-1]]=mp[x];
                mp[x+mp[x+1]]=mp[x];

                ans = max(ans, mp[x]);
            }
        }

        return ans;
    }
};
