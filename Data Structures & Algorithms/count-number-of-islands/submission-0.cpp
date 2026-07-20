class Solution {
public:
    void dfs(vector<vector<char>> &grid, int m, int n, int i, int j){
        vector<pair<int, int> > dirs = {{0,1}, {1,0}, {0,-1}, {-1, 0}};

        int x, y;
        for(auto curr: dirs){
            x = i+curr.first; y = j+curr.second;
            if(x>=0 && x<m && y>=0 && y<n){
                if(grid[x][y]=='1'){
                    grid[x][y] = '0';
                    dfs(grid, m, n, x, y);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), cnt=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid, m, n, i, j);
                }
            }
        }

        return cnt;
    }
};
