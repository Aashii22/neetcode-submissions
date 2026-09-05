class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();

        vector<vector<int> > ans;
        priority_queue<pair<float, int>, vector<pair<float, int> >, greater<pair<float, int> > > pq;

        for(int i=0; i<n; i++){
            pq.push({sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]), i});
        }

        while(k>0 && !pq.empty()){
            ans.push_back({points[pq.top().second][0], points[pq.top().second][1]});
            k--;
            pq.pop();
        }

        return ans;
    }
};
