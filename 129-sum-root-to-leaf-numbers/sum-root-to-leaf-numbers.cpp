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
    int findPaths(TreeNode * root,int curr_Num){
        if(!root) return 0;

        curr_Num=curr_Num * 10 + root->val;
        

        if(!root->left && !root->right){
           return curr_Num;
        } 

        return findPaths(root->left,curr_Num) + findPaths(root->right,curr_Num);
                                        
        return curr_Num;

    }
    int sumNumbers(TreeNode* root) {

        return findPaths(root,0); 
   
    }
};