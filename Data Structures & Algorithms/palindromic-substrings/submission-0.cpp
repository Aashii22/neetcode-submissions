class Solution {
public:
    int find(string s, int l, int r){
        int n = s.length();

        while(l>=0 && r<n){
            if(s[l]==s[r])
            l--, r++;
            else
            break;
        }
        return r-l-1;
    }
    int countSubstrings(string s) {
        int n = s.length(), ans=0;

        for(int i=0; i<n; i++){
            ans += 1 + (find(s, i, i)-1)/2;
            if(i<n-1)
            ans += s[i]==s[i+1] ? find(s, i, i+1)/2 : 0;

            //cout<<ans<<endl;
        }

        return ans;
    }
};
