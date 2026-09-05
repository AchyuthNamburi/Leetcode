class Solution {
public:
    bool ispossible(int mid,vector<int>& nums){
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) return false;
        }

        return true;
    }
    long long minOperations(vector<int>& nums) {
        int n=nums.size();

        long long  low=0;
        long long max_diff=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                max_diff+=nums[i-1]-nums[i];
            }
        }
        long long high=max_diff;

        // int high=*max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end());

        while(low<high){
            long long  mid=low+(high-low)/2;
            if(ispossible(mid,nums)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};