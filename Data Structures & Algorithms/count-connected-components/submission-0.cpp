class Solution {
public:
    vector<int> parent;
    int findParent(int u){
        if(u==parent[u])
        return u;
        else
        return parent[u] = findParent(parent[u]);
    }
    void unionOf(int u, int v){
        int rootU = findParent(u);
        int rootV = findParent(v);

        parent[rootV] = rootU;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        for(auto edge: edges){
            unionOf(edge[0], edge[1]);
        }

        int cnt=0;
        for(int i=0; i<n; i++){
            if(i==findParent(i))
            cnt++;
        }

        return cnt;
    }
};
