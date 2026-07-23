class Solution {
public:
    // Hint we will have only 2 cases !
    // either it will stay in LOOP or it will converge to 1 
    // if it is converging to 1 then it is Happy
    //else it is not happy

    int solve(int x){
        int sum=0;
        while(x){
            int last=x%10;
            sum+=last * last;
            x/=10;
        }

        return sum;
    }
    bool isHappy(int n) {

        unordered_map<int,int> mp;

        while(n!=1){
            if(mp.find(n)!=mp.end()){
                return false;
            }
            else{
                mp[n]++;
            }
            n=solve(n);
        }

        return true;
    }
};