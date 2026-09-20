class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int sum=0;
        
        for(int i=0;i<n;i++){
            auto ch=s[i];
            int val=abs(ch-123);
            cout<<val;
            int prod=val*(i+1);
            sum+=prod;
        }

        return sum;
    }
};