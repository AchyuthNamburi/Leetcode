class Solution {
public:
    bool check_upper(string& word){
        for(auto it:word){
            if(!isupper(it)){
                return false;
            }
        }
        return true;
    }

    bool check_lower(string& word){
        for(auto it:word){
            if(!islower(it)){
                return false;
            }
        }
        return true;
    }

    bool first_capital(string& s){
        for(int i=0;i<s.length();i++){
            if(i==0 && !isupper(s[0])){
                return false;
            }
            else if(i>0 && isupper(s[i])){
                return false;
            }

        }

        return true;
    }

    bool detectCapitalUse(string word) {
        bool lower=false;

        if(check_upper(word)) return true;
        if(check_lower(word)) return true;
        if(first_capital(word)) return true;

        return false;

    }
};