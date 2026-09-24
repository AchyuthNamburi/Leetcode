class Solution {
public:
    bool solve(string& s, int l, int r){
        while(l<r){
            if(s[l]==s[r]){
                l++;
                r--;
            }
            else{
                return false;
            }
        }

        return true;
    }
    bool validPalindrome(string s) {
        int n=s.length();
        int i=0;
        int j=n-1;

        while(i<j){
            // if(i==j) return true;
            if(i==j) return true; 
            if(s[i]==s[j]){
                i++;
                j--;
            } 

            else{
                return solve(s,i+1,j) || solve(s,i,j-1);
            }
            
        }

        return true;
    }
};