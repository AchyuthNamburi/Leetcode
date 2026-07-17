class Solution {
public:
    // idea found the mid if posssible using BInary search
    // else use the upper bound of the binary search to find the index to be stored
    int solve(vector<int>& nums, int target,int low,int high){
        int res=nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]>=target){
                res=mid;
                high=mid-1;
                
            }
            else{
                low=mid+1;
            }
        }

        return res;
    }
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(nums,target,0,n-1);
    }
};