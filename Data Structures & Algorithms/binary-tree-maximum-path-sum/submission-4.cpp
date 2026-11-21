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

class Solution {
public:
    int ans = 0;
    int solve(TreeNode* &root){
        if(!root)
        return 0;

        int l = solve(root->left), r = solve(root->right);

        int curr = max(root->val, root->val + max(l, r));
        //cout<<root->val<<" "<<curr<<endl;
        ans = max(ans, max(max(root->val+l+r, root->val), max(root->val+l, root->val+r)));
        return curr;
    }
    int maxPathSum(TreeNode* root) {
        ans = root->val;

        solve(root);

        return ans;
    }
};
