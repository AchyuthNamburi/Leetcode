class Solution {
public:
    int maxDepth(string s) {
       stack<char> st;
       int maxi=0;
       int cnt=0;
       for(auto ch : s){
            if(ch=='('){
                cnt++;
                maxi=max(maxi,cnt);
            }
            else if(ch==')'){
                cnt--;
            }
       }

       return maxi; 
    }
};