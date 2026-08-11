class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        if(t.length()!=s.length()) return false;

        for(auto it : t){
            mp[it]++;
        }

        for(auto it:s){
            if(mp.find(it)!=mp.end()){
                mp[it]--;
                if(mp[it]==0) mp.erase(it);
            }
        }

        return mp.size()==0;
    }
};