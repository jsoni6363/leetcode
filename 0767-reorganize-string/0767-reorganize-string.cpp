class Solution {
public:
    string reorganizeString(string s) {

        // Step 1: Count frequency of each character
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Step 2: Check if reorganization is possible
        int maxFreq = 0;
        for (int i = 0; i < 26; i++) {
            maxFreq = max(maxFreq, freq[i]);
        }

        // If any character appears too many times, it's impossible
        if (maxFreq > (s.size() + 1) / 2) {
            return "";
        }

        // Step 3: Build the result string
        string result = "";

        while (result.size() < s.size()) {

            // Find character with maximum remaining frequency
            int firstIdx = findMaxIndex(freq);
            char firstChar = 'a' + firstIdx;

            // Add it to result
            result += firstChar;
            freq[firstIdx]--;

            // If this character is now exhausted, move on
            if (freq[firstIdx] == 0) {
                continue;
            }

            // Temporarily block this character
            int savedFreq = freq[firstIdx];
            freq[firstIdx] = -1;

            // Find next most frequent character
            int secondIdx = findMaxIndex(freq);
            char secondChar = 'a' + secondIdx;

            // Add second character
            result += secondChar;
            freq[secondIdx]--;

            // Restore the first character frequency
            freq[firstIdx] = savedFreq;
        }

        return result;
    }

private:
    // Finds index of character with maximum frequency
    int findMaxIndex(const vector<int>& freq) {
        int maxIdx = 0;
        for (int i = 1; i < 26; i++) {
            if (freq[i] > freq[maxIdx]) {
                maxIdx = i;
            }
        }
        return maxIdx;
    }
};
