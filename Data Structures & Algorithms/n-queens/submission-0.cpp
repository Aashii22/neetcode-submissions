class Solution {
public:
    vector<vector<string> > ans;
    unordered_set<int> col;
    unordered_set<int> pos_diag;
    unordered_set<int> neg_diag;
    void dfs(int n, int i, vector<string> &tmp){
        if(i>=n){
            ans.push_back(tmp);
            return;
        }

        for(int j=0; j<n; j++){
            if(col.count(j) || pos_diag.count(i+j) || neg_diag.count(i-j)){
                continue;
            }
            else{
                col.insert(j);
                pos_diag.insert(i+j);
                neg_diag.insert(i-j);

                tmp[i][j] = 'Q';
                dfs(n, i+1, tmp);

                col.erase(j);
                pos_diag.erase(i+j);
                neg_diag.erase(i-j);
                tmp[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> tmp(n, string(n, '.'));
        dfs(n, 0, tmp);

        return ans;
    }
};
