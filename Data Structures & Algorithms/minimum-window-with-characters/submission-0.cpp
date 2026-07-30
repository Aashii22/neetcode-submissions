class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length(), n = t.length();

        unordered_map<char, int> mp;
        for(char x: t){
            mp[x]++;
        }


        int l=0, r=0, curr=0;
        string ans = "";
        while(r<m){
            if(mp[s[r]]>0)
            curr++;

            mp[s[r]]--;

            if(curr==n){
                while(l<=r && mp[s[l]]<0){
                    mp[s[l++]]++;
                }
                
                if(ans=="" || ans.length()>r-l+1){
                    ans = s.substr(l, r-l+1);
                }
            }
            r++;
        }

        return ans;
    }
};
