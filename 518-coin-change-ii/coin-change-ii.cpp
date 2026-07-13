class Solution {
public:
    // here it is not about finding the minimum coins 
    // it is about finding the no of ways we can achieve the amount
    int solve(vector<int>& coins,int n , int amount,vector<vector<long long>>& dp){
      // i---> coins
        // j---> target sum

        for(int i=0;i<=n;i++){
            dp[i][0]=1;        // one way to achieve the amount=0   
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                     dp[i][j]= dp[i][j-coins[i-1]] + dp[i-1][j] ;

                    dp[i][j]=min(dp[i][j],(long long) INT_MAX);
                                
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][amount] >= INT_MAX-1 ? -1 : dp[n][amount];  
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();

        vector<vector<long long>> dp(n+1,vector<long long> (amount+1,0));

        return solve(coins,n,amount,dp);
    }
};