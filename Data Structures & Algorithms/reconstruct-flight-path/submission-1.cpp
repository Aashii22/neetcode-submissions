class Solution {
public:
    void dfs(unordered_map<string, vector<string> > &mp, string curr, vector<string> &ans){

        while(!mp[curr].empty()){
            string dest = mp[curr].back();
            mp[curr].pop_back();
            dfs(mp, dest, ans);
        }
        ans.push_back(curr);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int edge = tickets.size();

        unordered_map<string, vector<string> > mp;
        for(auto &edge: tickets){
            mp[edge[0]].push_back(edge[1]);
        }

        for(auto &x: mp){
            sort(x.second.begin(), x.second.end(), greater<string>());
        }
        vector<string> ans;
        dfs(mp, "JFK", ans);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
