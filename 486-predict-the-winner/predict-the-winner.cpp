class Solution {
public:
    // Returns the maximum score difference
    // (current player score - opponent score)
    int solve(vector<int>& nums, int left, int right) {

        // Only one element left
        if (left == right)
            return nums[left];

        // Pick left
        int pickLeft = nums[left] - solve(nums, left + 1, right);

        // Pick right
        int pickRight = nums[right] - solve(nums, left, right - 1);

        // Choose the better option
        return max(pickLeft, pickRight);
    }

    bool predictTheWinner(vector<int>& nums) {

        return solve(nums, 0, nums.size() - 1) >= 0;
    }
};