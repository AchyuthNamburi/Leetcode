class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m; //storing sum  , idx

        m[0]=-1;
        int sum=0;
        int len=0;
        int maxi=INT_MIN;

        for(int i=0;i<n;i++){
            if(nums[i]==0) sum+=-1;
            else sum+=1;

            if(m.find(sum)!=m.end()){ //if sum already present in map then find len
                len=i-m[sum]; 
                maxi=max(len,maxi);
            }
            else{
                m[sum]=i;  //store its index in map
            }
        }

        return max(maxi,0);

    }
};