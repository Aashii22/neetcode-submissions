class TrieNode {
public:
    bool isLast;
    unordered_map<char, TrieNode*> children;

    TrieNode(){
        isLast = false;
    }

    void addWord(string &word){
        TrieNode* curr = this;
        for(char c: word){
            if(!curr->children.count(c)){
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->isLast = true;
    }
};
class Solution {
public:
    unordered_set<string> ans;
    vector<vector<bool> > vis;
    void dfs(vector<vector<char> > &board, int i, int j, TrieNode* root, string currWord){
        if(root->isLast){
            ans.insert(currWord);
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || vis[i][j] || !root->children.count(board[i][j])){
            return;
        }
        vis[i][j] = true;
        root = root->children[board[i][j]];
        currWord += board[i][j];

        dfs(board, i+1, j, root, currWord);
        dfs(board, i-1, j, root, currWord);
        dfs(board, i, j+1, root, currWord);
        dfs(board, i, j-1, root, currWord);

        vis[i][j] = false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string word: words){
            root->addWord(word);
        }
    
        int m = board.size(), n = board[0].size();
        vis.assign(m, vector<bool>(n, false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                dfs(board, i, j, root, "");
            }
        }

        return vector<string>(ans.begin(), ans.end());
    }
};
