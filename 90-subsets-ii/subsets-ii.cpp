class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums,int idx,vector<int>& temp){
            // everytime we have to push into ans
            ans.push_back(temp); // key diff bet the combination sum 2 and subset sum 2

        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;

            temp.push_back(nums[i]);
            solve(nums,i+1,temp);// pick
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       // same for loop recursion
       // we dont need not pick case

       vector<int> temp;
       sort(nums.begin(),nums.end());

       solve(nums,0,temp);
       return ans;
    }
};