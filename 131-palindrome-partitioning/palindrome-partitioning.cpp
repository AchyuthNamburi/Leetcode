class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;

    bool isPallindrome(string s,int start,int end){
        while(start < end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;
    }

    void solve(string s,int start){
        if(start==s.size()){
            ans.push_back(path);
            return;
        }

        for(int end=start;end<s.length();end++){
            if(isPallindrome(s,start,end)){
                path.push_back(s.substr(start,end-start+1)); //choose

                solve(s,end+1); // explore remaining

                path.pop_back(); // backtrack
            }
        }

        
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();

        solve(s,0);
        return ans;
    }
};