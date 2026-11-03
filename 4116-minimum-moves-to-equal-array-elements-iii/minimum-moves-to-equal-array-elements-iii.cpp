class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();

        int target=*max_element(nums.begin(),nums.end());

        int sum=0;
        for(int i=0;i<n;i++){
            sum+=abs(nums[i]-target);
        }

        return sum;
    }
};