class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long n=nums.size();

        int i=0;
        int j=0;

        int total_sum=accumulate(nums.begin(),nums.end(),0);
        long long target=total_sum-x;
        long long curr_win_sum=0;
        long long maxi=-1;

        //idea ---> think in a reverse direction 
        //instead of removing first and last elem ...we are finding the longest contiguous subarray sum which makes the target
        
        while(j<n){
            curr_win_sum+=nums[j];
            //shrink if needed
            while(curr_win_sum>target && i<=j){
                curr_win_sum-=(long long)nums[i];
                i++;
            }
            // check if target reached or not after shrinking
            if(curr_win_sum==target){
                maxi=max(maxi,(long long)j-i+1);
            }
            j++;
            
        }

        if(maxi==-1) return -1;
       return n-maxi;


    }
};