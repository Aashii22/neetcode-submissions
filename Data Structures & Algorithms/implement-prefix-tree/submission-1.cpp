struct TrieNode{
    bool isLast;
    TrieNode* alpha[26];
    TrieNode(){
        isLast = false;
        for(int x=0; x<26; x++){
            alpha[x] = NULL;
        }
    }
};
class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void add(string &word, int idx, TrieNode* root){
        if(idx==word.size()){
            root->isLast = true;
            return;
        }
        else{
            if(!root->alpha[word[idx]-'a']){
                root->alpha[word[idx]-'a'] = new TrieNode();
            }
            add(word, idx+1, root->alpha[word[idx]-'a']);
        }
    }
    void insert(string word) {
        add(word, 0, root);
    }
    
    bool solveSearch(string &word, int idx, TrieNode* root){
        if(idx==word.size()){
            return root->isLast;
        }
        else{
            if(!root->alpha[word[idx]-'a'])
            return false;
            
            return solveSearch(word, idx+1, root->alpha[word[idx]-'a']);
        }

    }
    bool search(string word) {
        return solveSearch(word, 0, root);
    }
    
    bool solvePrefix(string &word, int idx, TrieNode* root){
        if(idx==word.size()){
            return true;
        }
        else{
            if(!root->alpha[word[idx]-'a'])
            return false;
            
            return solvePrefix(word, idx+1, root->alpha[word[idx]-'a']);
        }
    }
    bool startsWith(string prefix) {
        return solvePrefix(prefix, 0, root);
    }
};
