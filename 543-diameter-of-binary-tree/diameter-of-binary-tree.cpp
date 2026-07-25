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

        int left_ht=1+solve(root->left);
        int right_ht=1+solve(root->right);

        maxDia=max(maxDia,left_ht+right_ht-2); // observe we are solving the maxDia using height of the tree. 
        //but in the question it is asked using the no of edges ....so we did -2 (one for left and one for right)

        return max(left_ht,right_ht);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxDia=0;
        solve(root);

        return maxDia;
    }
};