class Solution {
public:
    bool stoneGame(vector<int>& piles) {
       //The length of the piles is always even.
        //The total number of stones is odd, so a tie is impossible.

        // Since Alice always has a choice between the two parities, she can always obtain the parity with the larger total sum.

        //Consequently, Bob is left with the parity having the smaller total sum.
        // Alice is  guaranteed to collect more stones than Bob
        
        return true;
    }
};