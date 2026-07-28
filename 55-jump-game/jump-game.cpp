class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();

        int reachable_idx=0;

        for(int i=0;i<n;i++){
            if(i>reachable_idx) return false;
            reachable_idx=max(reachable_idx,i+nums[i]);
        }

        return true;

        
    }
};