class Solution {
public:
    int m, n;
    vector<vector<int> > dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int dfs(vector<vector<int> > &grid, int i, int j){
        int x, y, cnt=1;

        for(auto w: dirs){
            x = i + w[0];
            y = j + w[1];

            if(x>=0 && x<m && y>=0 && y<n && grid[x][y]==1){
                grid[x][y] = 0;
                cnt+=dfs(grid, x, y);
            }
        }

        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    grid[i][j] = 0;
                    ans = max(ans, dfs(grid, i, j));
                }
            }
        }

        return ans;
    }
};
