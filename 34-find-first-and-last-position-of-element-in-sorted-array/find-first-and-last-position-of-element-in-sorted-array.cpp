class Solution {
public:
    //idea is to use binary search ..lower bound and the upper bound

    int first_occu(vector<int>& nums, int target,int low,int high){
        int res=-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target){
                res=mid;
                high=mid-1; 
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return res;
    }
    int last_occu(vector<int>& nums, int target,int low,int high){
        int res=-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target){
                res=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{
                 high=mid-1;
            }
        }

        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        return {first_occu(nums,target,0,n-1) , last_occu(nums,target,0,n-1)};
    }
};