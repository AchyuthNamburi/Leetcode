class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi=INT_MIN;

        int n=nums.size();

        int i=0;
        int j=1;

        while(j<n){
            if(nums[j]>nums[j-1]){
                j++;  
            }
            else{
                maxi=max(maxi,j-i); 
                i=j;
                j++;
            }
        }
        maxi=max(maxi,j-i);

        i=0;
        j=1;
        while(j<n){
            if(nums[j]<nums[j-1]){
                j++;  
            }
            else{
                maxi=max(maxi,j-i); 
                i=j;
                j++;
            }
        }
        maxi=max(maxi,j-i);
        

        return maxi;
    }
};