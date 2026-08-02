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
    TreeNode* solve(TreeNode * root){
        if(!root) return root;
        
        TreeNode * temp=root->right;
        root->right=root->left;
        root->left=temp;

        auto left=solve(root->left);
        auto right=solve(root->right);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        return solve(root);
    }
};