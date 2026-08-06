class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int m=queries.size();
        int n=queries[0].size();

        vector<int> diff(nums.size()+1,0);

        for(auto it : queries){
            int left=it[0];
            int right=it[1];
            
            diff[left]++;
            if(right+1<nums.size())
              diff[right+1]--;
           
        }
        int prefix=0;
        
        // just calc prefix sum
        for(int i=0;i<nums.size();i++){
            prefix+=diff[i];
            // here prefix is saying no of decrements we can do
            // now check if the no of decrements is less than the value ..we can't make it 0 ryt 
            if(prefix < nums[i]) return false;
        }

        return true;

    }
};