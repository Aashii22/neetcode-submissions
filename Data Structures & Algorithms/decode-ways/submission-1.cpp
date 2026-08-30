class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();

        vector<int> dp(n+1, 0);
        dp[n] = 1;
        if(s[n-1]!='0')
        dp[n-1] = 1;

        int num;
        for(int i=n-2; i>=0; i--){
            num = (s[i]-'0')*10 + (s[i+1]-'0');
            if(num>=10 && num<=26){
                dp[i] = dp[i+2] + dp[i+1];
            }
            else if(s[i]>='1' && s[i]<='9'){
                dp[i] = dp[i+1];
            }
        }

        return dp[0];
    }
};
