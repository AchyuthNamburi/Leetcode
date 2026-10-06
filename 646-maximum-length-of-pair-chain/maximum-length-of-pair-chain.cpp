class Solution {
public:
    int solve(int i,int prev,int n,vector<vector<int>>& pairs,vector<vector<int>>& dp){
        if(i>=n) return 0;

        if(prev!=-1 && dp[i][prev+1]!=-1) return dp[i][prev+1];
        // prev+1 since it can has -1 value also

        int take = 0;
        if(prev == -1 || pairs[i][0] > pairs[prev][1])
            take = 1+solve(i+1,i,n,pairs,dp); // i becomes prev ...since we are taking that
        
        int skip = solve(i+1,prev,n,pairs,dp); // prev remains same !
        
          dp[i][prev+1] =  max(take, skip);
        
        return dp[i][prev+1];

    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        sort(pairs.begin(),pairs.end());  // since it was given that we can choose the pairs in any order
        int prev=-1;

        return solve(0,prev,n,pairs,dp);
    }
};
