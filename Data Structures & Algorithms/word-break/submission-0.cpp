class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        unordered_map<string, bool> mp;
        for(auto &x: wordDict){
            mp[x] = true;
        }
        mp[""] = true;

        vector<bool> dp(n+1, false);
        dp[n] = true;
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<=n; j++){
                if(mp[s.substr(i, j-i)]){
                    dp[i] = dp[i] || dp[j];
                }
                if(dp[i])
                break;
            }
        }

        return dp[0];
    }
};
