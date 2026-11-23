class Solution {
public:
    vector<int> parent;
    int findParent(int u){
        if(u==parent[u])
        return u;
        else
        return parent[u] = findParent(parent[u]);
    }
    bool unionOf(int u, int v){
        int rootU = findParent(u);
        int rootV = findParent(v);

        if(rootU==rootV)
        return false;

        parent[rootV] = rootU;
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1)
        return false;

        parent.resize(n);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        for(auto edge: edges){
            if(!unionOf(edge[0], edge[1]))
            return false;
        }

        return true;
    }
};
