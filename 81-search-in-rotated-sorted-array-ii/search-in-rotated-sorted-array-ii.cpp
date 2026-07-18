class Solution {
public:
    bool solve(vector<int>& nums, int target,int low,int high){
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                return true;
            }

            if(nums[mid]==nums[low] && nums[mid]==nums[high]){ 
                low++;
                high--;
                continue; // when all three values are equal then only we cannot distinguish which part is sorted 
            }
            

            //check if the left part is sorted or right part
            if(nums[mid] >= nums[low]){
                if(nums[mid] > target && target>=nums[low]){ //if left sorted
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{                                                  // if right sorted
                if(nums[mid] < target && target <= nums[high]){ 
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