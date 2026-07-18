class Solution {
public:
    int inf = pow(2, 31)-1;
    void bfs(vector<vector<int> > &grid, int i, int j, int m, int n){
        queue<pair<int, int> > q;
        q.push({i, j});

        int sz, cnt=1, x, y;
        vector<pair<int, int> > dirs = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
        while(!q.empty()){
            sz = q.size();
            while(sz--){
                auto [curr_x, curr_y] = q.front();
                q.pop();

                for(auto j: dirs){
                    x = curr_x + j.first;
                    y = curr_y + j.second;
                    if(x>=0 && x<m && y>=0 && y<n){
                        if(grid[x][y]==-1 || grid[x][y]==0)
                        continue;
                        else{
                            if(grid[x][y]>cnt){
                                q.push({x, y});
                                grid[x][y] = min(grid[x][y], cnt);
                            }
                        }
                    }
                }
            }
            cnt++;
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    bfs(grid, i, j, m, n);
                }
            }
        }
    }
};
