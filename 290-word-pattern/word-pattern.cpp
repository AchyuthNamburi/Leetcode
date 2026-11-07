class Solution {
public:
    bool wordPattern(string pattern, string s) {

        vector<string> temp;

        string word = "";

        for (char c : s) {
            if (c == ' ') {
                temp.push_back(word);
                word = "";
            }
            else {
                word += c;
            }
        }
        temp.push_back(word); // Add last word

        unordered_map<string,char> mp1;
        unordered_map<char,string> mp2;


        if(pattern.length()!=temp.size()) return false;

        for(int i=0;i<pattern.length();i++){
            if(mp1.find(temp[i])==mp1.end() && mp2.find(pattern[i])==mp2.end()){
                mp1[temp[i]]=pattern[i];
                mp2[pattern[i]]=temp[i];
            }
            else{
                if(mp1[temp[i]]!=pattern[i] || mp2[pattern[i]]!=temp[i]) return false;

            }
            
        }

        return true;
        
    }
};