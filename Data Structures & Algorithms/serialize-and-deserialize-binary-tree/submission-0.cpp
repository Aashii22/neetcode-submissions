/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    void solve(TreeNode* &root, vector<string> &ans){
        if(!root){
            ans.push_back("#");
            return;
        }
        ans.push_back(to_string(root->val));
        solve(root->left, ans);
        solve(root->right, ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> ans;
        solve(root, ans);

        string res = "";
        for(int i=0; i<ans.size(); i++){
            res += ans[i];
            res += " ";
        }

        return res;
    }

    TreeNode* constructTree(vector<string> &ans, int &idx){
        if(idx>=ans.size())
        return NULL;

        if(ans[idx]=="#"){
            idx++;
            return NULL;
        }

        //cout<<idx<<endl;
        TreeNode* node = new TreeNode(stoi(ans[idx++]));
        node->left = constructTree(ans, idx);
        node->right = constructTree(ans, idx);

        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.length();

        vector<string> ans;
        int start=0;
        for(int i=0; i<n; i++){
            if(data[i]==' '){
                ans.push_back(data.substr(start, i-start));
                start=i+1;
            }
        }
        int idx = 0;
        return constructTree(ans, idx);
    }
};
