class Solution {
public:
    int solve(int index, string &s, int &n,vector<int>& dp) {
        if (index == n)
            return 1;
        if (s[index] == '0') // starting 0 is invalid
            return 0;

        if(dp[index]!=-1){
            return dp[index];
        }

        // Option 1: Decode the current digit alone
        int oneDigitWays = solve(index + 1, s, n,dp);

        // Option 2: Decode the current and next digit together
        int twoDigitWays = 0;

        if (index + 1 < n &&
            (s[index] == '1' ||
             (s[index] == '2' && s[index + 1] <= '6'))) { // if it is valid

            twoDigitWays = solve(index + 2, s, n,dp);
        }

        return dp[index]=oneDigitWays + twoDigitWays;
    }

    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        return solve(0, s, n,dp);
    }
};