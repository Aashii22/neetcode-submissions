class TrieNode{
public:
    bool endOfWord;
    TrieNode* child[26];
    TrieNode(){
        endOfWord = false;
        for(int i=0; i<26; i++){
            child[i] = NULL;
        }
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        int n = word.size();
        TrieNode* curr = root;
        for(int i=0; i<n; i++){
            if(!curr->child[word[i]-'a']){
                curr->child[word[i]-'a'] = new TrieNode();
            }
            curr = curr->child[word[i]-'a'];
        }
        curr->endOfWord = true;
    }

    bool solve(string &word, int idx, TrieNode* curr){
        if(!curr)
        return false;
        else if(idx==word.size()){
            return curr->endOfWord;
        }
        else{
            if(word[idx]=='.'){
                for(int i=0; i<26; i++){
                    if(curr->child[i]){
                        if(solve(word, idx+1, curr->child[i]))
                        return true;
                    }
                }
                return false;
            }
            else{
                return solve(word, idx+1, curr->child[word[idx]-'a']);
            }
        }
    }
    bool search(string word) {
        return solve(word, 0, root);
    }
};
