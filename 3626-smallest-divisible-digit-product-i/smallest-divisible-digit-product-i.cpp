class Solution {
public:
    int smallestNumber(int n, int t) {

        for(int i=n;i<=101;i++){
            int prod=1;
            int curr=i;
            while(curr){
                int last=curr%10;
                prod*=last;
                curr/=10;
            }

            if(prod%t==0) return i;
        }

        return -1;

        


    }
};