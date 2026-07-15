class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";

        for(auto ch:s){
            if(ch=='('){
                if(st.empty()){
                    st.push(ch);
                }
                else{
                    st.push(ch);
                    ans+=ch;
                }
            }
            else{
                st.pop();
                if(!st.empty())
                    ans += ')';
            }  
        }

        return ans;
    }
};