class Solution {
public:
    int solve(string & text1, string & text2,int m,int n,vector<vector<int>>& dp){
        if(m==0 || n==0){
            return 0;
        }

        if(dp[m][n]!=-1){
            return dp[m][n];
        }

        if(text1[m-1]==text2[n-1]){
            return  dp[m][n]=1+solve(text1,text2,m-1,n-1,dp);
        }
        
        return  dp[m][n]=max(solve(text1,text2,m-1,n,dp),
                        solve(text1,text2,m,n-1,dp));
        

    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length();
        int n=text2.length();

        vector<vector<int>> dp(m+1,vector<int> (n+1,-1));

        return solve(text1,text2,m,n,dp);
    }
};