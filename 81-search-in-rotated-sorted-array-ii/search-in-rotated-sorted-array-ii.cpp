class Solution {
public:
    bool solve(vector<int>& nums, int target,int low,int high){
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target) return true;

            // Handle duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            
            else if(nums[low]<=nums[mid]){ //left sorted
                if(target>=nums[low] && target<nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }

            else{
                if(target>nums[mid] && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }

        return false;
    }
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(nums,target,0,n-1);
    }
};