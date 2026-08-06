class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.length();

        vector<int> diff(n+1,0);
        
        for(auto it : shifts){
            int left=it[0];
            int right=it[1];
            int dir=it[2];

            if(dir==1){
                diff[left]++;
                diff[right+1]--;
            } 

            if(dir==0){
                diff[left]--;
                diff[right+1]++;
            } 

        }
        
        string ans="";
        int prefix=0;
        for(int i=0;i<diff.size()-1;i++){
            prefix+=diff[i];
            int shift=(s[i]-'a'+prefix)%26;
            
            if(shift<0){
                shift+=26;
            }

            ans+=(char)('a'+shift);

        }

        return ans;
    }
};