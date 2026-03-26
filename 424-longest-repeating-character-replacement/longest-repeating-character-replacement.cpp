class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxCount = 0;
        int i = 0;
        int maxLen = 0;

        for (int j = 0; j < s.size(); j++) {
            count[s[j] - 'A']++;

            // update max frequency
            maxCount = max(maxCount, count[s[j] - 'A']);

            // shrink window if invalid
            while ((j - i + 1) - maxCount > k) {
                count[s[i] - 'A']--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};