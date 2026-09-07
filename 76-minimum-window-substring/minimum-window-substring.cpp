class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        unordered_map<char, int> mp;
        // Frequency of characters required from t
        for(char ch : t) {
            mp[ch]++;
        }
        int i = 0, j = 0;
        int count = t.size();

        int minLen = INT_MAX;
        int start = 0;

        while(j < n) {
            // Include s[j] in the window
            if(mp[s[j]] > 0) {
                count--;
            }
            mp[s[j]]--;

            // Window is valid
            while(count == 0) {
                // Update minimum answer
                if(j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }
                // Remove s[i] from the window
                mp[s[i]]++;

                if(mp[s[i]] > 0) {
                    count++;
                }
                i++;
            }
            j++;
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};