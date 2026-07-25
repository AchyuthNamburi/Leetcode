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
    int height(TreeNode* root){
         if(root==NULL) return 0;
        
        int left_ht=1+height(root->left);
        int right_ht=1+height(root->right);

        return max(left_ht,right_ht);

    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        
        int left_ht=height(root->left);
        int right_ht=height(root->right);

        if(abs(left_ht-right_ht)>1) return false;

        return (isBalanced(root->left) && isBalanced(root->right));
    }
};