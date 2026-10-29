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
    void inorder(TreeNode* root,vector<int>& temp){
        
        if(!root) return;

        inorder(root->left,temp);
        temp.push_back(root->val);
        inorder(root->right,temp);

        return ;

    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> ans;
       inorder(root,ans);
        int sum=0;

        for(auto it : ans){
            cout<<it;
        }

        for(int i=0;i<ans.size();i++){
            if(ans[i]>=low && ans[i]<=high){
                sum+=ans[i];
            }
        }

        return sum;
    }
};