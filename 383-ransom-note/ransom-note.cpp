class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;

        for(auto it:magazine){
            mp[it]++;
        }

        for(auto it:ransomNote){
            if(mp.find(it)==mp.end() || mp[it]==0){
                return false;
            }
            mp[it]--;
            // if(mp[it]==0) mp.erase();
        }

        return true;
    }
};