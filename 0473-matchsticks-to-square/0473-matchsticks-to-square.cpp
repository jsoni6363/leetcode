class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {

        // ---------------------------------------------------
        // STEP 1: Find total length of all matchsticks
        // ---------------------------------------------------
        int totalLength = 0;
        for (int x : matchsticks) totalLength += x;

        // ---------------------------------------------------
        // STEP 2: If total is not divisible by 4, square impossible
        // ---------------------------------------------------
        if (totalLength % 4 != 0) return false;

        // ---------------------------------------------------
        // STEP 3: Each side must have this length
        // ---------------------------------------------------
        int length = totalLength / 4;

        // ---------------------------------------------------
        // STEP 4: 4 sides initialized with 0 length
        // ---------------------------------------------------
        vector<int> sides(4, 0);

        // ---------------------------------------------------
        // STEP 5: Sort matchsticks in descending order
        // (place big sticks first for faster failure)
        // ---------------------------------------------------
        sort(matchsticks.rbegin(), matchsticks.rend());

        // ---------------------------------------------------
        // STEP 6: Start backtracking from index 0
        // ---------------------------------------------------
        return dfs(matchsticks, sides, 0, length);
    }

private:

    // ---------------------------------------------------
    // dfs(...)
    // index = which matchstick we are placing
    // sides  = current 4 side lengths
    // length = required side length
    // ---------------------------------------------------
    bool dfs(vector<int>& matchsticks, vector<int>& sides, int index, int length) {

        // ---------------------------------------------------
        // BASE CASE:
        // All matchsticks placed successfully
        // ---------------------------------------------------
        if (index == matchsticks.size()) {
            return true;
        }

        // ---------------------------------------------------
        // Try putting matchstick[index] into each side
        // ---------------------------------------------------
        for (int i = 0; i < 4; i++) {

            // ------------------------------------------------
            // Only place if it doesn't exceed required length
            // ------------------------------------------------
            if (sides[i] + matchsticks[index] <= length) {

                // CHOOSE
                sides[i] += matchsticks[index];

                // EXPLORE
                if (dfs(matchsticks, sides, index + 1, length)) {
                    return true;
                }

                // UNCHOOSE (BACKTRACK)
                sides[i] -= matchsticks[index];
            }

            // ------------------------------------------------
            // OPTIMIZATION:
            // If this side is still 0 after trying,
            // no need to try other empty sides
            // ------------------------------------------------
            if (sides[i] == 0) break;
        }

        // ---------------------------------------------------
        // No valid placement found
        // ---------------------------------------------------
        return false;
    }
};
