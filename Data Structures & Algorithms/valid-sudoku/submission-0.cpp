class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool> > rows(10, vector<bool>(10, false));
        vector<vector<bool> > cols(10, vector<bool>(10, false));
        vector<vector<bool> > box(10, vector<bool>(10, false));

        int id;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                id = (i/3)*3 + (j/3);
                if(board[i][j] == '.')
                continue;
                else if(rows[i][board[i][j]-'0'] || cols[j][board[i][j]-'0'] || box[id][board[i][j]-'0'])
                return false;
                else{
                    rows[i][board[i][j]-'0'] = true;
                    cols[j][board[i][j]-'0'] = true;
                    box[id][board[i][j]-'0'] = true;
                }
            }
        }

        return true;
    }
};
