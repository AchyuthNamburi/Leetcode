class Solution {
public:
    bool canWinNim(int n) {
        
        //observe the pattern for every 4th multiple ...u will lose
        return !(n%4==0);


    }
};