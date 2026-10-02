class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int> > q;
        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }
                else if(grid[i][j]==1)
                cnt++;
            }
        }

        if(cnt==0)
        return 0;

        int ans = 0, sz, x, y, u, v;
        vector<pair<int, int> > dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!q.empty()){
            sz = q.size();
            while(sz--){
                x = q.front().first;
                y = q.front().second;
                q.pop();

                for(auto p: dirs){
                    u = x + p.first;
                    v = y + p.second;
                    if(u>=0 && v>=0 && u<m && v<n && grid[u][v]==1){
                        cnt--;
                        grid[u][v] = 2;
                        q.push({u, v});
                    }
                }
            }
            ans++;

            if(cnt==0)
            return ans;
        }

        return -1;
    }
};
