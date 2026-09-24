class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();

        // int maxi=*max_element(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            int sum=0;
            int curr=nums[i];
            while(curr){
                sum+=curr%10;
                curr=curr/10;
            }
            if(sum==i) return i;
        }

        return -1;
    }
};