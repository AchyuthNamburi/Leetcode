class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();

        vector<int> ans;
        for(int l=0;l<n;l++){
            for(int r=0;r<n;r++){
                if(l!=r && nums[l]+nums[r]==target){
                    ans.push_back(l);
                    ans.push_back(r);
                    return ans;
                }
            }
        }
        return {};
    }
};