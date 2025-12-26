class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        // count[0] -> 'a', count[1] -> 'b', count[2] -> 'c'
        vector<int> count = {a, b, c};

        // Result string
        string res;

        // This stores the index of character we are NOT allowed to use
        // because last two characters are same
        int repeated = -1;

        while (true) {

            // Pick the character with the maximum count
            // excluding the repeated one
            int maxChar = getMax(count, repeated);

            // If no valid character exists, stop
            if (maxChar == -1) {
                break;
            }

            // Add chosen character to result
            res += char(maxChar + 'a');

            // Reduce its available count
            count[maxChar]--;

            // If last two characters are same,
            // block this character in next step
            if (res.size() > 1 && res.back() == res[res.size() - 2]) {
                repeated = maxChar;
            } else {
                // Otherwise, no restriction
                repeated = -1;
            }
        }

        return res;
    }

private:
    int getMax(const vector<int>& count, int repeated) {

        int idx = -1;       // index of selected character
        int maxCnt = 0;     // maximum count found

        // Check for 'a', 'b', 'c'
        for (int i = 0; i < 3; i++) {

            // Skip blocked character or exhausted ones
            if (i == repeated || count[i] == 0) {
                continue;
            }

            // Pick character with maximum remaining count
            if (count[i] > maxCnt) {
                maxCnt = count[i];
                idx = i;
            }
        }

        // Return selected character index
        // or -1 if no valid character exists
        return idx;
    }
};
