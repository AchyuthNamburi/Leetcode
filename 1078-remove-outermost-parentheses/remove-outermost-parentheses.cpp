class Solution {
public:
    string removeOuterParentheses(string s) {
        // approach using counter 
        // ( ---> +1
        // ) ----> -1
        // if the counter value is not 0 then add it to the ans 

        int counter=0;
        string ans="";

        for(auto ch : s){
            if(ch=='('){
                if(counter!=0) ans+=ch; 
                counter++;
            }
            else{
                counter--;
                if(counter!=0){
                    ans+=ch;
                }
            }
        }
        return ans;
    }
};