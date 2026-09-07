class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxSoFar = nums[0];
        int minSoFar = nums[0];
        int result = maxSoFar;

        for (int i = 1; i < nums.size(); ++i) {
            int curr = nums[i];
            int tempMax = max({curr, maxSoFar * curr, minSoFar * curr});
            minSoFar = min({curr, maxSoFar * curr, minSoFar * curr});

            maxSoFar = tempMax;
            result = max(result, maxSoFar);
        }
        return result;
    }
};