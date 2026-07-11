class Solution {
public:
    bool solve(vector<int>& nums,int n,int total_sum,vector<vector<bool>>& dp){
        for(int i=0;i<=n;i++){
         for(int j=0;j<=total_sum;j++){
             if(j==0){ // total_sum=0 we can get with any elem so TRUE
                 dp[i][j]=true;
             }
         }
     }
     
     for(int i=1;i<=n;i++){
         for(int j=1;j<=total_sum;j++){
             if(nums[i-1]<=j){
                dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }
            else {
                dp[i][j]=dp[i-1][j];
            }
         }
     }
     
     return dp[n][total_sum];
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total_sum=0;

        for(auto it: nums){
            total_sum+=it;
        }

        vector<vector<bool>> dp(n+1, vector<bool>(total_sum/2+1, false));

        if(total_sum%2!=0) return false;

        return solve(nums,n,total_sum/2,dp);
    }
};