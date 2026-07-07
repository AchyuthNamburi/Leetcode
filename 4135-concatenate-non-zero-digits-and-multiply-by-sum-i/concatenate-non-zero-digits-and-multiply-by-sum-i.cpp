class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);

        string res="";

        for(auto it:s){
            if(it!='0'){
                res+=it;
            }
        }

        int x;
        if(res.length()==0){
            x=0;
        }
        else{
             x=stoi(res);
        }

        long long temp=x;

        long long sum=0;
        while(x){
            sum+=x%10;
            x/=10;
        }

        long long ans=temp*sum;

        return ans;

    }
};