class Solution {
public:
bool isSubset(const std::set<char>& setA, const std::set<char>& setB) {
    for (auto x : setA) {
        if (setB.find(x) == setB.end()) {
            return false; // Element in setA is missing from setB
        }
    }
    return true;
}
    int countConsistentStrings(string allowed, vector<string>& words) {
        //for this my idea is taking a set for both allowed and then each word in words 

        // i have to make the set and then have to equal them and chekc

        set<char> st1;

        for(auto it :allowed){
            st1.insert(it);
        }

        int cnt=0;

        for(auto it :words){
            set<char> st2;
            for(auto jt:it){
                st2.insert(jt);
            }
            if(isSubset(st2,st1)) cnt++;
            
        }

        return cnt;
        
    }
};