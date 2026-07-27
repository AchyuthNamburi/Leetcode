class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root==p || root==q){
            return root;
        }

        TreeNode* leftN=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightN=lowestCommonAncestor(root->right,p,q);

        if(rightN!=NULL && leftN!=NULL){ // both are returning some values
            return root;
        }
        if(leftN!=NULL){ // only one is returning
            return leftN;
        }
        return rightN;

    }
};