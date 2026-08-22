class Solution {
public:
    int solve(int i,int prev,int n,vector<int>& nums,vector<vector<int>>& dp){
        if(i>=n) return 0;

        if(prev!=-1 && dp[i][prev]!=-1) return dp[i][prev];

        int take = 0;
        if(prev == -1 || nums[i] > nums[prev])
            take = 1+solve(i+1,i,n,nums,dp);
        
        int skip = solve(i+1,prev,n,nums,dp);
        
        if(prev!= -1)
            dp[i][prev] =  max(take, skip);
        
        return max(take, skip);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int prev=-1;

        return solve(0,prev,n,nums,dp);
    }
};