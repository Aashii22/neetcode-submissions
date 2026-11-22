class Solution {
public:
    int find(string s, int l, int r){
        int n = s.length(), cnt=0;

        while(l>=0 && r<n && s[l]==s[r]){
            l--, r++;
            cnt++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int n = s.length(), ans=0;

        for(int i=0; i<n; i++){
            ans += find(s, i, i);
            ans += find(s, i, i+1);

            //cout<<ans<<endl;
        }

        return ans;
    }
};
