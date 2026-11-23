class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n+1, 0);
        vector<vector<int> > adj(n+1);

        int u,v;
        for(auto &edge: edges){
            u = edge[0];
            v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        queue<int> q;
        for(int i=0; i<n+1; i++){
            if(indegree[i]==1)
            q.push(i);
        }

        int sz=0, curr;
        while(!q.empty()){
            sz = q.size();
            while(sz--){
                curr = q.front();
                q.pop();
                for(int x: adj[curr]){
                    indegree[x]--;
                    if(indegree[x]==1)
                    q.push(x);
                }
            }
        }

        for(int i=n-1; i>=0; i--){
            if(indegree[edges[i][0]]==2 && indegree[edges[i][1]]==2)
            return edges[i];
        }

        return {};
    }
};
