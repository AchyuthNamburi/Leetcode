class Solution {
public:
    unordered_map<string, int> dp; // here we are using unordered_map ...since we have negative values of curr_sum also . 
    

    int solve(vector<int>& nums, int target, int i, int curr_sum) {

        if (i == nums.size()) {
            return (curr_sum == target);
        }

        string key = to_string(i) + "_" + to_string(curr_sum); // adding _ to make sure that no conflicts bet the idx and curr_sum

        if (dp.find(key) != dp.end())
            return dp[key];

        int plus = solve(nums, target, i + 1, curr_sum + nums[i]);
        int minus = solve(nums, target, i + 1, curr_sum - nums[i]);

        return dp[key] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0);
    }
};