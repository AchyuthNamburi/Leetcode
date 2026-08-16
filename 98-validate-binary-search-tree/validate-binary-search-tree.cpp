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
    bool solve(TreeNode* root,long long min_val, long long max_val){
        // if(!root) return true;
        // if(root->left && root->left->val >= root->val){
        //     return false;
        // }
        // if(root->right && root->right->val <= root-> val){
        //    return false;
        // }

        // return solve(root->left) && solve(root->right); //  this is just checking the immediate children...not the entire tree
        // or simply u can do using this inorder of the BST and check if any elem is > the prev elem

        if(!root) return true;
        if(root->val<=min_val || root->val >=max_val) return false;

        return solve(root->left,min_val,root->val) && 
                solve(root->right,root->val,max_val); //careful 

        
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;

        return solve(root,LLONG_MIN, LLONG_MAX);
    }
};