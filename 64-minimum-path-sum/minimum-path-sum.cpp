class Solution {
public:
    int dp[202][202];
    int solve(int r,int c,int m,int n,vector<vector<int>>& grid){
        if(r==m-1 && c==n-1) return grid[r][c];
        if(r>=m || c>=n) return INT_MAX;

        if(dp[r][c]!=-1) return dp[r][c];

        int sum=0;
        sum+=grid[r][c];
        int f1=solve(r+1,c,m,n,grid);
        int f2=solve(r,c+1,m,n,grid);

        sum+=min(f1,f2);
        return dp[r][c]=sum;
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(dp,-1,sizeof(dp));

        return solve(0,0,m,n,grid);
        
    }
};