class Solution {
public:
    bool isindict(string& curr, vector<string>& wordDict) { 
        if (find(wordDict.begin(), wordDict.end(), curr) != wordDict.end()) { // will take O(n) ---so its better to use unordered-set
            return true;
        }
        return false;
    }

    void solve(int idx, string &s, vector<string>& wordDict,
               string &temp, vector<string>& ans) {

        if (idx == s.length()) {
            ans.push_back(temp);
            return;
        }

        for (int j = idx; j < s.length(); j++) {
            string curr = s.substr(idx, j - idx + 1);
            if (isindict(curr, wordDict)) {
                string old = temp;
                temp += curr + " ";
                solve(j + 1, s, wordDict, temp, ans);   // <-- changed
                temp = old;
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        string temp = "";
        solve(0, s, wordDict, temp, ans);

        for(auto &it:ans)
            it.erase(it.size()-1); // removes the last space at end of sentence

        return ans;
    }
};