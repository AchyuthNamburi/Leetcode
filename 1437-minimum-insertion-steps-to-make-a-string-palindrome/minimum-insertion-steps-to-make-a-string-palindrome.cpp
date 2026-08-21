class Solution {
public:
    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        // Base cases
        if(i >= j) {
            return 0;  // Empty or single character is already palindrome
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // If characters match, move inward
        if(s[i] == s[j]) {
            dp[i][j] = solve(s, i+1, j-1, dp);
        } else {
            // Option 1: Insert at beginning to match s[j]
            // Option 2: Insert at end to match s[i]
            dp[i][j] = 1 + min(solve(s, i+1, j, dp),    // Insert s[i] at position j+1
                               solve(s, i, j-1, dp));    // Insert s[j] at position i-1
        }
        
        return dp[i][j];
    }
    
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, n-1, dp);
    }
};