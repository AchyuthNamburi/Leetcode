class Solution {
public:
    int dp[55][55][55][55];  // Since n <= 50 (constraints from problem)

    int solve(int r1,int c1,int r2,int c2,int m,int n,vector<vector<int>>& grid){
        if(r1>=m || r2>=m || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;

        if(dp[r1][c1][r2][c2]!=-1){
            return dp[r1][c1][r2][c2];
        }

        if(r1==m-1 && c1==n-1){ //if they reach destination
            return grid[r1][c1];
        }

        int cherries=0;
        if(r1==r2 && c1==c2){
            cherries+=grid[r1][c1]; // add only once
        }
        else{
            cherries+=grid[r1][c1]+grid[r2][c2]; //add both
        }

        int f1=solve(r1,c1+1,r2,c2+1,m,n,grid);//h,h
        int f2=solve(r1+1,c1,r2+1,c2,m,n,grid);//v,v
        int f3=solve(r1+1,c1,r2,c2+1,m,n,grid);//v,h
        int f4=solve(r1,c1+1,r2+1,c2,m,n,grid);//h,v
        
        cherries+=max(max(f1,f2),max(f3,f4));
        return dp[r1][c1][r2][c2]=cherries;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        memset(dp,-1,sizeof(dp));

        int ans=solve(0,0,0,0,m,n,grid);
        return max(ans,0);
       
    }
};