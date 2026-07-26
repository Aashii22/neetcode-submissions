class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp;

        string key;
        for(auto &s: strs){

            vector<int> freq(26, 0);
            
            for(auto &x: s){
                freq[x-'a']++;
            }
            key = to_string(freq[0]);
            for(int i=1; i<26; i++){
                key += ',' + to_string(freq[i]);
            }
            mp[key].push_back(s);
        }

        vector<vector<string> > ans;
        for(auto& x: mp){
            ans.push_back(x.second);
        }

        return ans;
    }
};
