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
        // traverse level wise and at alternative level reverse push the elem into the ans

        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;

        while(!q.empty()){
            vector<int> temp;
            
            int size=q.size();
            //for loop is used to traverse level wise 
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr){
                    temp.push_back(curr->val);
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
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