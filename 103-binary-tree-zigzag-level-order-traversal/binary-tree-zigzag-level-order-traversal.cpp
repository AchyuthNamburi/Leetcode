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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        

        vector<vector<int>> ans;

        if(root==NULL) return {};

        queue<TreeNode*> q;
        q.push(root);

        int level=0;
        while(!q.empty()){
            vector<int> temp;
            int size=q.size();

            for(int i=0;i<size;i++){
                TreeNode* curr_elem=q.front();
                q.pop();
                if(curr_elem){
                    temp.push_back(curr_elem->val);
                }
                if(curr_elem->left){
                    q.push(curr_elem->left);
                }
                if(curr_elem->right){
                     q.push(curr_elem->right);
                }  
            }
            level++;
            if(level%2==0){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);

        }
        

        return ans;
    }
};