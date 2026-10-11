class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        //idea 
        //only 3 possibilities
        int sr=source[0];
        int sc=source[1];
        int tr=target[0];
        int tc=target[1];
        
        if(sr==tr && sc==tc) return 0;
        
        if((sr+sc)%2 != (tr+tc)%2){ //parity (color is diff)
            return -1;
        }

        if(abs(tr-sr)==abs(tc-sc)) return 1; //in the same diagonal

        return 2; //it is in the same color but diff diagonal

    }
};