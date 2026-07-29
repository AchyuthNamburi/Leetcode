class Solution {
public:
    // Check whether s[left...right] is a palindrome
    bool isPalindrome(string &s, int left, int right) {

        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    string longestPalindrome(string s) {

        int n = s.length();

        if (n == 0)
            return "";

        int maxLength = 0;
        int startIndex = 0;

        // Generate all possible substrings using indices
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Check directly without creating a new string
                if (isPalindrome(s, i, j)) {
                    int currentLength = j - i + 1;
                    if (currentLength > maxLength) {
                        maxLength = currentLength;
                        startIndex = i;
                    }
                }
            }
        }
        
        return s.substr(startIndex, maxLength);
    }
};