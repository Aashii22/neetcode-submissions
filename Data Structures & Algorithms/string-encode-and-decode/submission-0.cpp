class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;

        int len;
        for(auto &s: strs){
            len = s.length();
            ans+=to_string(len)+"#"+s;
        }

        return ans;
    }

    vector<string> decode(string s) {
        int n = s.length();

        int i=0, j, len;
        string curr;
        vector<string> ans;

        while(i<n){

            j=i;
            while(s[j]!='#'){
                j++;
            }
            len = stoi(s.substr(i, j-i));
            j++;
            curr = "";

            while(len--){
                curr+=s[j++];
            }

            ans.push_back(curr);
            i=j;
        }
        return ans;
    }
};
