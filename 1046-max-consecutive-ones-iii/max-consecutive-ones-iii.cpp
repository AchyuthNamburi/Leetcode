class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //reverse thinking
        //Instead of thinking about flipping zeros, think about finding a window (contiguous subarray) that contains at most k zeros.

        int n=nums.size();
        int i=0,j=0;
        int zeros=0;

        int maxi=0;

        while(j<n){
            if(nums[j]==0){
                zeros++;
            }
            if(zeros<=k){
                maxi=max(maxi,j-i+1);
                j++;
            }
            else if(zeros>k){
                while(zeros>k){
                    if(nums[i]==0){
                        zeros--;
                    }
                    i++;
                }
                maxi=max(maxi,zeros);
                j++;
            }
        }

        return maxi;
    }
};