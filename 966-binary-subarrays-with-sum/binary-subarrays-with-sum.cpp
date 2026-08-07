// return atmost(goal) - atmost(goal - 1)
class Solution {
public:
int atmost(int goal, vector<int>& nums){
    if(goal < 0) return 0;
    int n = nums.size();
    int i=0,j=0;
    long long sum = 0;
    int count = 0;
    while(j<n){
        sum+=nums[j];
        if(sum <= goal){
            count+=(j-i+1); // this formula you should know i.e number of subarrays
            // all ending at index j
            j++;
        }
        else{
            while(sum > goal){
                sum-=nums[i];
                i++;
            }
            count+=(j-i+1); // this is needed bcz after shrinking there are 
            // valid subarrays as well
            j++;
        }
    }
    return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(goal,nums) - atmost(goal-1,nums);
    }
};