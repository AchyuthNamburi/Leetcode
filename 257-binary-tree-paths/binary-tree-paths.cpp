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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL) return ans;

        if(!root->left && !root->right){
            ans.push_back(to_string(root->val));
        }

        vector<string> left,right;

        if(root->left){
            left=binaryTreePaths(root->left);
        }
        if(root->right){
            right=binaryTreePaths(root->right);
        }

        for(string path:left){
            ans.push_back(to_string(root->val)+"->"+path);
        }

        for(string path:right){
            ans.push_back(to_string(root->val)+"->"+path);

        }

        return ans;
    }
};