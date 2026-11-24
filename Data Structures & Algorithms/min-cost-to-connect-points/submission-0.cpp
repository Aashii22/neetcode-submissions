class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), edges = 0;
        vector<int> dist(n, INT_MAX);
        vector<bool> vis(n, false);

        int node = 0, ans=0, nextNode, currDist;
        while(edges<n-1){
            vis[node] = true;
            nextNode=-1;
            for(int i=0; i<n; i++){
                if(vis[i])
                continue;

                currDist = abs(points[i][0]-points[node][0]) + abs(points[i][1]-points[node][1]);

                dist[i] = min(dist[i], currDist);
                if(nextNode==-1 || dist[i]<dist[nextNode]){
                    nextNode = i;
                }
            }
            node = nextNode;
            ans+=dist[nextNode];
            edges++;
        }

        return ans;
    }
};
