class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        unordered_map<int,int> mp;
        long long sum=0;
        long long maxi=INT_MIN;


        while(j<n){
            mp[nums[j]]++;
            sum+=nums[j];
            if(j-i+1<k){
                j++;
            }

            else if(j-i+1==k){
                if(mp.size()==k){ // nice idea to check distinct elem
                    maxi=max(maxi,sum);
                }
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                sum-=nums[i];

                i++;
                j++;
            }
        }

        return maxi==INT_MIN ? 0 :maxi;

    }
};