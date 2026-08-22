class Solution {
public:
    bool solve(int i,int j,int m,int n,vector<vector<int>>& dp,string& s, string & p){
        if(i >= m && j >= n) return true; // this is crucial and it should be at the starting
        if(j >= n) return false;
        if(i >= m){
            //we have to check whether all the remaining char are * or not 
            while(j<n){
                if(p[j]!='*') return false;
                j++;
            }

            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        //if both char matches
        if(s[i]==p[j] || p[j]=='?' ){
           return  dp[i][j]=solve(i+1,j+1,m,n,dp,s,p);
        }

        if(p[j]=='*'){
            bool consume=solve(i+1,j,m,n,dp,s,p);
            bool dont_consume=solve(i,j+1,m,n,dp,s,p);
            return dp[i][j]= consume|| dont_consume;
        }
    

        return false;
    }
    bool isMatch(string s, string p) {
        int m=s.length();
        int n=p.length();

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        return solve(0,0,m,n,dp,s,p);
    }
};