class Solution {
public:
    int solve(int idx,vector<int>& nums,int amt,vector<int>& dp){
        
        if(idx>nums.size()-1){
            return amt;
        }

        if(dp[idx]!=-1){
            return dp[idx];
        }

        //take
        int take=nums[idx]+solve(idx+2,nums,amt,dp);

        //skip
        int skip=solve(idx+1,nums,amt,dp);

        return dp[idx]=max(amt+skip,amt+take);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int amt=0;

        vector<int> dp(n,-1);

        if(nums.size()==0){
            return amt;
        }

        return solve(0,nums,amt,dp);
    }
};