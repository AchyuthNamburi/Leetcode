class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();

        int cnt=0;

        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){  //checking for inversions 
                cnt++;
            }
        }
        if(nums[n-1]>nums[0]) cnt++; //crucial

        return cnt<=1;
    }
};