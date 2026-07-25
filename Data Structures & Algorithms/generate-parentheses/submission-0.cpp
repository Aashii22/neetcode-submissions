class Solution {
public:
    vector<string> ans;
    void solve(int open, int closed, int n, string curr){
        if(open + closed == 2*n){
            ans.push_back(curr);
            return;
        }

        if(open<n){
            solve(open+1, closed, n, curr+'(');
        }
        if(open>closed){
            solve(open, closed+1, n, curr+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(0, 0, n, "");
        return ans;
    }
};
