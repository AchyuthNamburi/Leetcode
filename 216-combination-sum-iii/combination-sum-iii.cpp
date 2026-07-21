class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums={1,2,3,4,5,6,7,8,9};

    void solve(int k,int n,int idx,int sum,vector<int> & temp){
        if(idx==nums.size()){
            if(temp.size()==k && sum==n){
                ans.push_back(temp);
            }
            return;
        }
        if(sum>n) return;

        temp.push_back(nums[idx]);
        solve(k,n,idx+1,sum+(long long)nums[idx],temp);
        temp.pop_back();
        solve(k,n,idx+1,sum,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> temp;
        long long sum=0;

        solve(k,n,0,sum,temp);
        return ans;
    }
};