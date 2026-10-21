class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long total=(1LL * n*(n-1))/2;

        unordered_map<int,int> m;            
        long long good = 0;

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;   //instead of generating all the pairs
                                    //we r counting the good pairs 
                                    //where nums[i]-i=nums[j]-j
                                    //and subtrqacting them total pairs

            good += m[key];
            m[key]++;
        }

        return total - good;
    }
};