class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();

        int l, r, cnt, ans=0;

        unordered_set<char> st;
        for(int i=0; i<n; i++){
            st.insert(s[i]);
        }

        for(char curr: st){

            l=0; r=0; cnt=k;
            //cout<<curr<<endl;
            while(r<n){

                if(s[r]!=curr){
                    cnt--;
                    while(l<=r && cnt<0){
                        if(s[l]!=curr)
                        cnt++;

                        l++;
                    }
                }

                //cout<<l<<" "<<r<<endl;
                ans = max(ans, r-l+1);
                r++;
            }
        }

        return ans;
    }
};
