class Solution {
public:
    static bool comparator(pair<int,int>& a,pair<int,int>& b){
        if(a.first == b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int,int> mp;

        for(auto it : nums){
            if(it%2==0){
                mp[it]++;
            }
            
        }

        vector<pair<int,int>> temp;
        for(auto it : mp){
            temp.push_back({it.second,it.first});
        }

        if(temp.size()==0){
            return -1;
        }

        sort(temp.begin(),temp.end(),comparator);

        return temp[0].second;
    }
};