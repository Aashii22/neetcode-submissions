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
    int idx=0;
    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int l, int r){
        if(l>r)
        return NULL;

        int mid = l;
        while(preorder[idx]!=inorder[mid]){
            mid++;
        }
        idx++;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = solve(preorder, inorder, l, mid-1);
        root->right = solve(preorder, inorder, mid+1, r);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(preorder, inorder, 0, preorder.size()-1);
    }
};
