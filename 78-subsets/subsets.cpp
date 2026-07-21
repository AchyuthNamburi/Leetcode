class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& nums,int idx,vector<int> & temp){
        if(idx==nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        solve(nums,idx+1,temp); //take
        temp.pop_back();
        solve(nums,idx+1,temp);// dont take
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(nums,0,temp);
        return ans;
    }
};