class Solution {
public:
    bool isValidTree(vector<vector<int> > &adj, unordered_set<int> &visit, int curr, int par){
        if(visit.count(curr))
        return false;

        visit.insert(curr);
        for(int x: adj[curr]){
            if(x==par){
                continue;
            }
            if(!isValidTree(adj, visit, x, curr))
            return false;
        }

        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1)
        return false;

        vector<vector<int> > adj(n);

        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visit;
        if(!isValidTree(adj, visit, 0, -1))
        return false;
        

        return visit.size()==n;
    }
};
