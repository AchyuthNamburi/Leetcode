class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int ss=shifts.size();
        for(int i=0;i<ss;i++){
            shifts[i]=shifts[i]%26;
        }

        long long total=accumulate(shifts.begin(),shifts.end(),0);

        vector<int> diff(shifts.size(),0);
        diff[0]=total;

        for(int i=1;i<ss;i++){
            diff[i]=diff[i-1]-shifts[i-1];
        }

        string ans="";
        int i=0;
        for(int i=0;i<s.length();i++){
            ans+=(s[i]-'a'+diff[i])%26 + 'a';
        }

        return ans;

    }
};