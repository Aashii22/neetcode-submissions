class Solution {
public:
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
    vector<string> ans;
    void dfs(string &digits, int i, string &tmp){
        if(i>=digits.length()){
            ans.push_back(tmp);
            return;
        }
        string s = digitToChar[digits[i]-'0'];
        for(int j=0; j<s.length(); j++){
            tmp.push_back(s[j]);
            dfs(digits, i+1, tmp);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.length();

        if(n==0)
        return ans;

        string s;
        dfs(digits, 0, s);

        return ans;
    }
};
