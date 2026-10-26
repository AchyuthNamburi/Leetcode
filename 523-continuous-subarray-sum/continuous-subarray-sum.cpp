class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();

        int sum=0;
        unordered_map<int,int> firstIdx; //sum ,idx
        firstIdx[0]=-1; //base condition ---> rem 0 is in -1 index

        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(firstIdx.find(rem)!=firstIdx.end()){
                if(i-firstIdx[rem] >= 2) return true;
            }
            else{
                    firstIdx[rem]=i;
                }
        }

        return false;
    }
};