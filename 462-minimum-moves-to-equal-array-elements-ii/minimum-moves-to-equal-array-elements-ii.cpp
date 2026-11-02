class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // idea is that median helps to find minimum sum of the absolute differences

        int n=nums.size();

        sort(nums.begin(),nums.end());

        long long target;

        if(n%2!=0){
            target=nums[n/2];
        }
        else{
            target= (nums[(n/2)-1] +nums[n/2])/2;
        }

         int sum=0;

        for(int i=0;i<n;i++){
            sum+=abs(nums[i]-target);
        }

        return sum;
    }
};