class Solution {
public:
    
    int solve(string word1, string word2,int m,int n,vector<vector<int>>& dp){
        if(m==0){
            return n;  // Need to insert n characters
        }
        if(n==0){
            return m;  // Need to delete m characters
        }

        if(dp[m][n]!=-1) return dp[m][n];
        
        if(word1[m-1]==word2[n-1]){
            dp[m][n] = solve(word1,word2,m-1,n-1,dp);  // No operation needed
        }
        else{
            int deleteOp_in_w1 = solve(word1,word2,m-1,n,dp) + 1;    // Delete s1[m-1]
            int deleteOp_in_w2 = solve(word1,word2,m,n-1,dp) + 1;
            
            dp[m][n] =min(deleteOp_in_w1,deleteOp_in_w2);
        }
        
        return dp[m][n];
    }
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
        return solve(word1,word2,m,n,dp);
    }
};