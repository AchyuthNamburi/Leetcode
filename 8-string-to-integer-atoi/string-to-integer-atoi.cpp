class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int i=0;
        while(i<n && s[i]==' ' ){
                i++;
        }
        if(i==n) return 0;

        int sign=+1;
        if(s[i]=='+'){
            sign=+1;
            i++;
        }
        else if(s[i]=='-'){
            sign=-1;
            i++;
        }
        if(i==n) return 0;
        if(!isdigit(s[i])){
            return 0;
        }
        long long ans=0;
        while(i<n && isdigit(s[i])){
            if(sign==+1 && ans*10+s[i]-'0' > INT_MAX){
                return INT_MAX;
            }
            if(sign==-1 && ans*10+s[i]-'0' >= (long long)INT_MAX+1){ // critical
                return INT_MIN;
            }
                ans=ans*10+s[i]-'0';
                i++;
        }

            return sign*ans;
    }
};