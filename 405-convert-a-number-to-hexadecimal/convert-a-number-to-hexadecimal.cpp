class Solution {
public:
    string toHex(int num) {

        if(num==0){
            return "0";
        }

        unsigned int n=(unsigned int) num;
        string ans="";
        string temp="0123456789abcdef";

        while(n){
            int rem=n%16;
            ans+=temp[rem];
            n=n/16;
        }

        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};