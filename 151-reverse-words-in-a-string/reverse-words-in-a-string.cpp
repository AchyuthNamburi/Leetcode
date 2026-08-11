class Solution {
public:
    string reverseWords(string s) {
        deque<string> dq;
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i] != ' ') {
                temp += s[i];
            }
            else {
                if(temp != "") {   // avoid empty words
                    dq.push_front(temp);
                    temp = "";
                }
            }
        }
        if(temp!="") dq.push_front(temp); // check the last word...

        string res="";

        while(!dq.empty()){
            res+=dq.front();
            dq.pop_front();

            if(!dq.empty()){
                res+=" ";
            }
        }

        return res;
    }
};