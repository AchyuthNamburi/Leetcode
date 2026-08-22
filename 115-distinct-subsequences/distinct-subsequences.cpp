class Solution {
public:
    long long solve(int i,int j,string & s ,string & t,vector<vector<long long>>& dp,int m,int n){
        if(i >= m && j >= n) return 1; // this is crucial and it should be at the starting
        if(i>=m) return 0;
        if(j>=n) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]){
            //if equal then we have 2 cases---> take , not_take
            int take=solve(i+1,j+1,s,t,dp,m,n);
            int not_take=solve(i+1,j,s,t,dp,m,n);

            return dp[i][j]=take+not_take;
        }
        else{
            
            return dp[i][j]=solve(i+1,j,s,t,dp,m,n);
        }

        return 0;

    }
    int numDistinct(string s, string t) {
        int m=s.length();
        int n=t.length();

        vector<vector<long long>> dp(m+1,vector<long long>(n+1,-1));

        return solve(0,0,s,t,dp,m,n);
    }
};