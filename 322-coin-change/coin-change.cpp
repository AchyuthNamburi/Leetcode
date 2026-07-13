class Solution {
public:
    const int INF=1e9;

    int solve(vector<int>& coins, int amount,int idx,int curr_sum,vector<vector<int>>& dp){

            if(curr_sum==amount){
                return 0;
            }
            if(idx==coins.size() || curr_sum > amount){
                return INF;
            }
        
        if(dp[idx][curr_sum]!=-1){
            return dp[idx][curr_sum];
        }

       int take = INF;

        if (coins[idx] <= amount - curr_sum) { // gaurdraills before doing recursion
            take = solve(coins, amount, idx, curr_sum + coins[idx], dp);

            if (take != INF)
                take = 1 + take;
        }

        int skip=solve(coins,amount,idx+1,curr_sum,dp);

        return dp[idx][curr_sum]=min(take,skip);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        // unbounded_knapsack
        int n=coins.size();
        // here 2 variables changes  ---> idx and curr_sum
       vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));

        int ans= solve(coins,amount,0,0,dp);

        return ans==INF ? -1 : ans;
    }
};