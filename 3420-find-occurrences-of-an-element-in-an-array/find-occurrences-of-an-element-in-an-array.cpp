class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        unordered_map<int,vector<int>> mp;
        int n=nums.size();

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        int m=queries.size();
        vector<int> ans(m);

        for(int i=0;i<m;i++){
            //  vector<int> temp=mp[x]; // saving the entire array each time is expensive
            if(mp[x].size() < queries[i]){
                ans[i]=-1;
            }
            else{
                ans[i]=mp[x][queries[i]-1];
            }
        }

        return ans;
    }
};