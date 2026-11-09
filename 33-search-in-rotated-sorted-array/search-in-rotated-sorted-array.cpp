class Solution {
public: 
    //find the sorted half 
    // and then decide which side we have to go 

    int solve(vector<int>& nums, int target,int low,int high){
        int res=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            

            if(nums[low]<=nums[mid]){ // left half is sorted
                if(nums[mid] == target)  return mid;
                   
                if(target>=nums[low] && target<=nums[mid]){
                    high=mid-1;
                }
                else{
                   low=mid+1; 
                }
            }
            else if(nums[mid]<=nums[high]){
               if(nums[mid] == target)  return mid;

               if(target>=nums[mid] && target<=nums[high]){
                    low=mid+1;
               }
               else{
                    high=mid-1;
               }
            } 
        }

        return res;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();

        return solve(nums,target,0,n-1);
    }
};