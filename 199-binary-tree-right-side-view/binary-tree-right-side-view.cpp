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
    vector<int> ans;
    void modified_preorder(TreeNode* root,int level){
        if(root==NULL) return;

        if(ans.size() < level){
            ans.push_back(root->val);
        }

        if(root->right) modified_preorder(root->right,level+1);
        if(root->left) modified_preorder(root->left,level+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        //idea is small tweak to the preorder traversal 
        // this time we will do  root->right->left 
        // also for each level if a node is added to ans ...then remaining all are discarded

        if(root==NULL) return ans;

        modified_preorder(root,1);

        return ans;
        
    }
};