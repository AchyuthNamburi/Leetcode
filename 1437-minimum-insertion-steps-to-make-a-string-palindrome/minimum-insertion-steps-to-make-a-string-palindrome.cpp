class Solution {
public:
    int minInsertions(string s) {
        //simple way is to find the LCS of string s and the reverse(s)
        
        string temp=s;
        reverse(s.begin(),s.end());

        //find the LCS bet this string s and rev string
        int n=s.length();

        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==temp[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
        }

        return n-dp[n][n];
    }
};