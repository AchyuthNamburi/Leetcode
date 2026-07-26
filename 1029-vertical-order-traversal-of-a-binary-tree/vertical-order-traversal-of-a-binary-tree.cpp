class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        if(root==NULL) return {{}};
        //col ---> row ---> values
        map<int, map<int,multiset<int>>> nodes;

        //node , (row,col)
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto p = q.front();
            q.pop();

            TreeNode* node=p.first;
            int row=p.second.first;
            int col=p.second.second;

            nodes[col][row].insert(node->val);

            if(node->left){
                q.push({node->left,{row+1,col-1}});
            }
            if(node->right){
                q.push({node->right,{row+1,col+1}});
            }

        }

        vector<vector<int>> ans;

        for(auto &c : nodes){
            vector<int> temp;
            for(auto &r : c.second){
                for(auto &k : r.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }

        return ans;


    }
};