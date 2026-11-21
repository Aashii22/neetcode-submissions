class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int> > v;
        for(int i=0; i<n; i++){
            v.push_back({position[i], speed[i]});
        }

        sort(v.begin(), v.end());

        double prevTime=0, currTime;
        int fleet=0;
        for(int i=n-1; i>=0; i--){
            currTime = (double)((double)(target-v[i].first)/v[i].second);
            if(currTime>prevTime){
                fleet++;
                prevTime = currTime;
            }
        }
        return fleet;
    }
};
