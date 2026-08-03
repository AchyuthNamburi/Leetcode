class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n=nums.size();

        sort(nums.rbegin(),nums.rend());
        int score=0;
        
        while(k--){
            score+=nums[0];
            nums[0]++;
        }

        return score;
    }
};