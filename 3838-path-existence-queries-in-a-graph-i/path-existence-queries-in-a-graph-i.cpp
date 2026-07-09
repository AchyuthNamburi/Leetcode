class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        // blocked[i] = 1 if we CANNOT move from i to i+1
        vector<int> blocked(n - 1, 0);

        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] > maxDiff)
                blocked[i] = 1;
        }

        // Prefix sum of blocked array
        vector<int> prefix(n, 0);

        for (int i = 0; i < n - 1; i++) {
            prefix[i + 1] = prefix[i] + blocked[i];
        }

        vector<bool> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            // Number of blocked edges between l and r
            if (prefix[r] - prefix[l] == 0)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};