class Solution {
public:
    string frequencySort(string s) {
        int n=s.length();

        unordered_map<char,int> mp;
        for(auto it :s ){
            mp[it]++;
        }
        vector<pair<int,char>> temp;
        for(auto &[key,val]: mp){
            temp.push_back({val,key});
        }

        sort(temp.rbegin(),temp.rend());

        string ans="";
        for(auto it : temp){
            while(it.first){
                 ans+=it.second;
                 it.first--;
            }
           
        }

        return ans;
    }
};