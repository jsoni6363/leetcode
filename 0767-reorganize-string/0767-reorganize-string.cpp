class Solution {
public:
    string reorganizeString(string s) {

        // Step 1: Count frequency of each character
        // freq[0] -> 'a', freq[1] -> 'b', ..., freq[25] -> 'z'
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Step 2: Find the character with maximum frequency
        int maxIdx = max_element(freq.begin(), freq.end()) - freq.begin();
        int maxFreq = freq[maxIdx];

        // Step 3: Check if rearrangement is possible
        // If the most frequent character appears too many times,
        // it is impossible to separate all of them
        if (maxFreq > (s.size() + 1) / 2) {
            return "";
        }

        // Step 4: Prepare result string with same length as input
        // Initially filled with spaces
        string res(s.size(), ' ');

        // This index is used to place characters
        // We start with even positions: 0, 2, 4, ...
        int idx = 0;

        // Character with maximum frequency
        char maxChar = 'a' + maxIdx;

        // Step 5: Place the most frequent character at even indices
        while (freq[maxIdx] > 0) {

            // Place the character
            res[idx] = maxChar;

            // Move to the next even index
            idx += 2;

            // Decrease its frequency
            freq[maxIdx]--;
        }

        // Step 6: Place all remaining characters
        for (int i = 0; i < 26; i++) {

            // Place character 'a' + i while it still has remaining count
            while (freq[i] > 0) {

                // If we go out of bounds (past last index),
                // switch to odd indices: 1, 3, 5, ...
                if (idx >= s.size()) {
                    idx = 1;
                }

                // Place the character
                res[idx] = 'a' + i;

                // Move to next alternate position
                idx += 2;

                // Decrease frequency
                freq[i]--;
            }
        }

        // Step 7: Return the rearranged string
        return res;
    }
};
