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
    int maxDia;
    int solve(TreeNode * root){
        if(root==NULL){
            return 0;
        }

        int left_ht=solve(root->left); //left ht

        int right_ht=solve(root->right);  //right ht

        maxDia=max(maxDia,left_ht+right_ht); 

        return 1+max(left_ht,right_ht); 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDia=0;
        solve(root);

        return maxDia;
    }
};