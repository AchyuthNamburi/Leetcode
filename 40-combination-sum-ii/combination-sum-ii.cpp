class Solution {
public:
    void solve(vector<int>& candidates,int idx,long long sum, int target,vector<vector<int>>& ans,vector<int>& temp){

        if(sum==target){
                ans.push_back(temp);
                return;
        }
        if(idx==candidates.size()){
            return;
        }

        if(sum>target) return; // dont forget this 

        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;

            if(sum + candidates[i] > target) break; // pruning

            temp.push_back(candidates[i]);
            solve(candidates,i+1,sum+(long long)candidates[i],target,ans,temp); //pick
            temp.pop_back(); // backtrack
            
            // we should not write the not pick case 
            //as this is another approach of solving recursive problem
        
        }

        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       // bounded knapsack ---> only once 

       sort(candidates.begin(),candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates,0,0,target,ans,temp);

        return ans;
    }
};