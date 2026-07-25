class Solution {
public:
    unordered_set<string> st; // using unordered_set to avoid O(n) lookup space using dict
    // check word break II if needed ...we used find()
    vector<int> dp;

    bool solve(int idx, string &s) {
        if(idx == s.length())
            return true;

        if(dp[idx] != -1)
            return dp[idx];

        for(int j = idx; j < s.length(); j++) {
            string curr = s.substr(idx, j - idx + 1);
            if(st.count(curr)) {
                if(solve(j + 1, s))
                    return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        st = unordered_set<string>(wordDict.begin(), wordDict.end());
        dp.assign(s.length(), -1);

        return solve(0, s);
    }
};