class Solution {
public:
    void solve(vector<int>& candidates,int idx,long long sum, int target,vector<vector<int>>& ans,vector<int>& temp){
        

        if(idx==candidates.size()){
            if(sum==target){
                ans.push_back(temp);
            }
            return;
        }

        if(sum>target) return;
        temp.push_back(candidates[idx]);
        solve(candidates,idx,sum+(long long)candidates[idx],target,ans,temp); //pick
        temp.pop_back();
        solve(candidates,idx+1,sum,target,ans,temp); // not pick

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //unbounded knapsack idea

        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates,0,0,target,ans,temp);

        return ans;
    }
};