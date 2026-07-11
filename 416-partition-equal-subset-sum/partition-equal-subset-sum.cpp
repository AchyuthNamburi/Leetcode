class Solution {
public:
    bool solve(vector<int>& nums,int n,int total_sum,vector<vector<int>>& dp){
        if(total_sum==0) return dp[n][total_sum]=true;
        if(n==0) return dp[n][total_sum]=false;

        if(dp[n][total_sum]!=-1){
            return dp[n][total_sum];
        }

        bool take=false;
        if(nums[n-1]<=total_sum){
            take=solve(nums,n-1,total_sum-nums[n-1],dp);
        }
        bool skip=solve(nums,n-1,total_sum,dp);

        return dp[n][total_sum]=take || skip;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total_sum=0;

        for(auto it: nums){
            total_sum+=it;
        }

        vector<vector<int>> dp(n+1,vector<int> (total_sum/2+1,-1));

        if(total_sum%2!=0) return false;

        return solve(nums,n,total_sum/2,dp);
    }
};