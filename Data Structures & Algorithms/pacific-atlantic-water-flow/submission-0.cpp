class Solution {
public:
    vector<vector<bool> > pac, atl;
    vector<vector<int> > dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    void solve(vector<vector<int> > &heights, int i, int j, vector<vector<bool> > &ocean){
        if(i==heights.size() || j==heights[0].size())
        return;

        ocean[i][j] = true;

        int x, y;
        for(auto dir: dirs){
            x = i+dir[0];
            y = j+dir[1];

            if(x>=0 && x<heights.size() && y>=0 && y<heights[0].size() && !ocean[x][y] && heights[i][j]<=heights[x][y]){
                solve(heights, x, y, ocean);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();

        pac.resize(m, vector<bool>(n, false));
        atl.resize(m, vector<bool>(n, false));

        for(int i=0, j=0; i<m || j<n; i++, j++){
            if(i<m){
                solve(heights, i, 0, pac);
                solve(heights, i, n-1, atl);
            }
            if(j<n){
                solve(heights, 0, j, pac);
                solve(heights, m-1, j, atl);
            }
        }

        vector<vector<int> > ans;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pac[i][j] && atl[i][j])
                ans.push_back({i, j});
            }
        }

        return ans;
    }
};
