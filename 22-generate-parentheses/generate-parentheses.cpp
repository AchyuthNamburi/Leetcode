class Solution {
public:
    void solve(int open,int close,string curr,int n, vector<string>& ans){
        if(curr.size()==n){
            ans.push_back(curr);
            return;
        }
        if(open<n/2){
            solve(open+1,close,curr+'(',n,ans);
        }
        if(close<open){
            solve(open,close+1,curr+')',n,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr="";

        solve(0,0,curr,2*n,ans);

        return ans;
    }
};