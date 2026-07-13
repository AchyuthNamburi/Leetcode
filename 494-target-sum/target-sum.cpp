class Solution {
public:
    
    int S;
    int solve(vector<int>& nums, int target, int i, int curr_sum,vector<vector<int>>& dp) {

        if (i == nums.size()) {
            return (curr_sum == target);
        }

        if(dp[i][curr_sum+S]!=-1){ // observe we are doing +S to handle the negative values of curr_sum
            return dp[i][curr_sum+S];
        }

        int plus = solve(nums, target, i + 1, curr_sum + nums[i],dp);
        int minus = solve(nums, target, i + 1, curr_sum - nums[i],dp);

        return dp[i][curr_sum+S] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();

        S=accumulate(nums.begin(),nums.end(),0); // find total sum 

        vector<vector<int>> dp(n+1,vector<int>(2*S+1,-1)); // observe we took 2times the size of the curr_sum to handle the negative cases of curr_sum
        return solve(nums, target, 0, 0,dp);
    }
};