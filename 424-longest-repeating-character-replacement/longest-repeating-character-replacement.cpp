
class Solution {
public:
    int characterReplacement(string s, int k) {
        //Track: The most frequent character in the current window
        // Condition: window_length - max_frequency ≤ k
        // Shrink when: window_length - max_frequency > k
        int n = s.length();
        int i = 0, j = 0;
        int ans = 0;

        unordered_map<char, int> mp;
        int max_freq = 0;

        while (j < n) {
            mp[s[j]]++;

            max_freq = 0;
            for (auto it : mp) {
                max_freq = max(max_freq, it.second);
            }

            int windowSize = j - i + 1;

            if (windowSize - max_freq <= k) {
                ans = max(ans, windowSize);
                j++;
            }
            else {
                while (windowSize - max_freq > k) {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0) mp.erase(s[i]);
                    i++;

                    max_freq = 0;  // calc max_freq again after shrinking the window
                    for(auto it : mp) {
                        max_freq = max(max_freq, it.second);
                    }
                    
                    windowSize = j - i + 1;
                }

                ans = max(ans, j - i + 1);
                j++;
            }
        }

        return ans;
    }
};
