class Solution {
public:
    string makeLargestSpecial(string s) {
        int sum=0;
        int start=0;                 // recursively make the larger string 
                                    // larger string can be made by starting with "1" and ending with "0"

        vector<string> spl;

        for(int i=0;i<s.length();i++){
            sum+=s[i]=='1' ? 1 : -1;

            if(sum==0){
                string inner=s.substr(start+1,i-start-1);
                spl.push_back("1"+makeLargestSpecial(inner)+"0");
                start=i+1;
            }
        }

        sort(spl.rbegin(),spl.rend());

        string result;
        for(string &str : spl) {
            result += str;
        }

        return result;
    }
};