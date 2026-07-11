// same as 1755. Closest Subsequence Sum. just small tweek
// meet in the middle concept

class Solution {
public: 
    void generate(vector<int> & nums,int index,int end,int count,int sum,vector<vector<int>>& subsetSum){
        if(index > end){
            return subsetSum[count].push_back(sum);
        }

        //take
        generate(nums,index+1,end,count+1,sum+nums[index],subsetSum);
        //skip
        generate(nums,index+1,end,count,sum,subsetSum);

    }

    int minimumDifference(vector<int>& nums) {
        int total_size=nums.size();

        int n=total_size/2;

        int total_sum=0;

        for(auto it: nums){
            total_sum+=it;
        }

         vector<vector<int>> left(n+1); //  given both partitions should contain exactly n elem  
         vector<vector<int>> right(n+1);

         generate(nums,0,n-1,0,0,left);
         generate(nums,n,total_size-1,0,0,right);

         //sort right half

         for(int i=0;i<=n;i++){
            sort(right[i].begin(),right[i].end());
         }

         int mini=INT_MAX;

         for(int leftcount=0; leftcount<=n; leftcount++){
            int rightcount=n-leftcount;

            for(auto leftsum : left[leftcount]){
                int target=total_sum/2 - leftsum;

                auto it =lower_bound(right[rightcount].begin(),right[rightcount].end(),target);

                if(it!=right[rightcount].end()){
                    int s1=leftsum + *it;
                    int s2=total_sum - s1;
                    mini=min(mini,abs(s1-s2));

                }

                if(it != right[rightcount].begin()){
                    --it;
                    int s1=leftsum + *it;
                    int s2=total_sum - s1;

                    mini=min(mini,abs(s1-s2));
                }
            }
         }

         return mini;   
    }
};