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
    int ans=0;

    vector<int> solve(TreeNode* root){
        if(!root) return {0,0};
        // sum+=root->val;
        
        vector<int> left=solve(root->left); // since null ptr is handled by base case
        vector<int> right=solve(root->right);

        int no_nodes=1+left[0]+right[0];
        int sum=root->val+left[1]+right[1];

        //checking avg
        if(root->val==(sum)/no_nodes) ans++;


        return {no_nodes,sum}; 
    }
    int averageOfSubtree(TreeNode* root) {
        int no_nodes=0;
        int sum=0;
        
        solve(root);

        return ans;

        

    }
};