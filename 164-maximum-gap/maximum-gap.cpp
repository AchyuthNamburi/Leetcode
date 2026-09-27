class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;

        sort(nums.begin(),nums.end());

        int maxi_diff=INT_MIN;

        for(int i=1;i<n;i++){
            int diff=nums[i]-nums[i-1];
            maxi_diff=max(maxi_diff,diff);
        }

        return maxi_diff;
    }
};