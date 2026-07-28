class TimeMap {
private:
    unordered_map<string, vector<pair<string, int> > > mp;
public:
    TimeMap() {

    }
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }

    string search(vector<pair<string, int> > &v, int time){
        int l=0, r=v.size()-1, mid;

        string ans="";
        while(l<=r){
            mid = l + (r-l)/2;

            if(v[mid].second>time){
                r = mid-1;
            }
            else{
                ans = v[mid].first;
                l = mid+1;
            }
        }

        return ans;
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        if(mp.find(key)!=mp.end()){
            return search(mp[key], timestamp);
        }
        else
        return ans;
    }
};
