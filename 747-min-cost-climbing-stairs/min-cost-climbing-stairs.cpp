class Solution {
public:
    int solve(int curr,int n,vector<int>& cost,vector<int>& dp){
        if(curr>=n) return 0;
        if(dp[curr]!=-1) return dp[curr];

        int jump_1_step=cost[curr]+solve(curr+1,n,cost,dp);
        int jump_2_step=cost[curr]+solve(curr+2,n,cost,dp);

        return dp[curr]=min(jump_1_step,jump_2_step);
        
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);

        int case1= solve(0,n,cost,dp); // start from 0th step
        int case2= solve(1,n,cost,dp); // start from 1st step

        return min(case1,case2);
        
    }
};