class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
                continue;
            }
            else{
                if(st.empty()) return false;

                else if(s[i]==')' && st.top()!='(' || s[i]=='}' && st.top()!='{' || s[i]==']' && st.top()!='['){
                    return false;

                }
                st.pop();  // <-- missing
            }
            

            
        }

        return st.empty();
    }
};