class Solution {
public:
    int dp[40001][3];

    int solve(int i, vector<int>& nums, int rem) {
        int n = nums.size();

        if (i == n) {
            return (rem == 0) ? 0 : INT_MIN / 2;
        }

        if (dp[i][rem] != -1)
            return dp[i][rem];

        int take = nums[i] + solve(i + 1, nums, (rem + nums[i]) % 3);
        int skip = solve(i + 1, nums, rem);

        return dp[i][rem] = max(take, skip);
    }

    int maxSumDivThree(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, 0);
    }
};