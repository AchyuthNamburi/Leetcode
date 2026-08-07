class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // variable size sliding window
        // we have to return max consecutive no of 1's

        

        int n=nums.size();
        int cnt=0;
       
        
        int max_cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cnt++;   
                max_cnt=max(cnt,max_cnt);
            }
            else{
                cnt=0;
            }
            
        }

        return max_cnt;
    }
};