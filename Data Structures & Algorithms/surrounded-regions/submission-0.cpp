class Solution {
public:
    vector<vector<int> > dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    void dfs(vector<vector<char> > &board, int i, int j, vector<vector<bool> > &vis){
        if(i==board.size() && j==board[0].size())
        return;

        //cout<<i<<" "<<j<<endl;
        vis[i][j] = true;
        int x, y;
        for(auto dir: dirs){
            x = i + dir[0];
            y = j + dir[1];

            if(x>=0 && x<board.size() && y>=0 && y<board[0].size() && board[x][y]=='O' && !vis[x][y]){
                dfs(board, x, y, vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n= board[0].size();

        vector<vector<bool> > vis(m, vector<bool>(n, false));

        for(int i=0, j=0; i<m || j<n; i++, j++){
            if(i<m){
                if(board[i][0]=='O'){
                    dfs(board, i, 0, vis);
                }
                if(board[i][n-1]=='O'){
                    dfs(board, i, n-1, vis);
                }
            }
            if(j<n){
                if(board[0][j]=='O'){
                    dfs(board, 0, j, vis);
                }
                if(board[m-1][j]=='O'){
                    dfs(board, m-1, j, vis);
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O' && !vis[i][j])
                board[i][j] = 'X';
            }
        }
    }
};
