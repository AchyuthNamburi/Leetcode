class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        double avg=0;
        double max_avg=INT_MIN;
        double sum=0;

        while(j<n){
            sum+=nums[j];
            
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                avg=sum/k;
                max_avg=max(max_avg,avg);
                sum-=nums[i];
                i++;
                j++;
            }
        }

        return max_avg;
    }
};