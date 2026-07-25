class Solution {
public:
    vector<string> ans;
    void solve(int open, int closed, int n, string &curr){
        if(open + closed == 2*n){
            ans.push_back(curr);
            return;
        }

        if(open<n){
            curr+='(';
            solve(open+1, closed, n, curr);
            curr.pop_back();
        }
        if(open>closed){
            curr+=')';
            solve(open, closed+1, n, curr);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(0, 0, n, curr);
        return ans;
    }
};
