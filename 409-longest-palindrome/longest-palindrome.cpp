class Solution {
public:
    int longestPalindrome(string s) {
        int oddcount=0;
        unordered_map<char,int> m;

        for(auto it : s){
            m[it]++;
            if(m[it]%2 ==1){
                oddcount++;
            }
            else{
                oddcount--;
            }
        }

        if(oddcount > 1){
            return s.length()-oddcount+1;  // remove all the oddcounts and just include anyone of the oddcount alphabet
        }

        return s.length();

        
    }
};