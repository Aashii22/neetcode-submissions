class Solution {
public:
    vector<vector<bool> > dp;
    vector<vector<string> > ans;
    void solve(string s, vector<string> &part, int i){
        if(i>=s.length()){
            ans.push_back(part);
            return;
        }
        for(int j=i; j<s.length(); j++){
            if(dp[i][j]){
                part.push_back(s.substr(i, j-i+1));
                solve(s, part, j+1);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();

        dp.resize(n, vector<bool>(n, false));

        for(int l=1; l<=n; l++){
            for(int i=0; i<=n-l; i++){
                dp[i][i+l-1] = (s[i]==s[i+l-1] && (i+1>i+l-2 || dp[i+1][i+l-2]));
            }
        }

        vector<string> part;
        solve(s, part, 0);

        return ans;
    }
};
