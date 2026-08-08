class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        int j=0;
        int m=haystack.length();
        int n=needle.length();

        int start=0;

        while(i<m){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                 if(j == n) { // if found return
                    return start;
                }
            }
            else{
                start++;
                i=start;
                j=0;
            }
        }

        return (j==n) ? start : -1;

       
    }
};