class Solution {
public:
    //Boyer --Moore  voting Algorithm
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();

        for(auto it : nums){
            mp[it]++;
        }

        vector<int> res;
        for(auto it : mp){
            if(it.second>floor(n/3)){
                res.push_back(it.first);
            }
        }

        return res;
    }
};