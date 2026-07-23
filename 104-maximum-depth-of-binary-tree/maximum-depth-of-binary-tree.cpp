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
    int solve(TreeNode * root){
        if(root==NULL) return 0;


        int left_ht=1+solve(root->left);
        int right_ht=1+solve(root->right);

        return max(left_ht,right_ht);

    }
    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};