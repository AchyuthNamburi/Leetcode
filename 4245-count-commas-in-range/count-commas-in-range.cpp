class Solution {
public:
    int countCommas(int n) {
        if(n<1000) return 0;

        int cnt=0;
        
        for(int i=1000;i<=n;i++){
            int digits=0;
            int temp=i;
            while(temp){
                int d=temp%10;
                digits++;
                temp/=10;
            }

            if(digits==4 || digits==5 || digits==6) cnt+=1;
            
            
        }

        return cnt;

        
    }
};