class Solution {
public:
    int solve(int curr,int n,vector<int>& costs,vector<int>& dp){
        if(curr>=n){
            return 0;
        }
        if(dp[curr]!=-1){
            return dp[curr];
        }
        int mini=INT_MAX;
        for(int i=1;i<=3;i++){
            int next=curr+i;
            if(next<=n){ // it should not reach out of bounds
                int temp=costs[next-1]+(next-curr)*(next-curr); // observe as it is 1 indexed ..we are using costs[next-1]
                mini=min(mini,temp+solve(next,n,costs,dp));
            } 
        }
        return dp[curr]=mini;
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+2,-1);
        return solve(0,n,costs,dp);
    }
};