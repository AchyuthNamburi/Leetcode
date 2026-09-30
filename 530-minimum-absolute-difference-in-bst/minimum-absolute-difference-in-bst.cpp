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
    vector<int> inorder;
    void solve(TreeNode* root){
        if(!root){
            return;
        }
        if(root->left) solve(root->left);
        inorder.push_back(root->val);
        if(root->right) solve(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        solve(root);

        int prev=inorder[0];
        int mini=INT_MAX;
        for(int i=1;i<inorder.size();i++){
            int diff=inorder[i]-prev;
            mini=min(mini,diff);

            prev=inorder[i];
        }

        return mini;
    }
};