class Solution {
public:
    int m, n;
    bool dfs(vector<vector<char> > &board, string &word, int idx, int i, int j){
        if(idx == word.size())
        return true;
        else if(i<0 || j<0 || i>=m || j>=n)
        return false;

        bool found = false;
        vector<pair<int, int> > dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int x, y;

        char tmp = board[i][j];
        board[i][j] = '0';

        for(auto k: dirs){
            x = k.first +i;
            y = k.second +j;

            if(x<m && y<n && x>=0 && y>=0 && word[idx]==board[x][y]){
                found = dfs(board, word, idx+1, x, y);
            }

            if(found)
            break;
        }

        board[i][j] = tmp;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();

        bool ans = false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==word[0]){
                    ans = dfs(board, word, 1, i, j);
                }
                if(ans)
                return ans;
            }
        }

        return false;
        
    }
};
