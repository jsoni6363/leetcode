class Solution {
public:

    // This will store all final combinations
    vector<string> result;

    // Phone keypad mapping
    vector<string> mapping = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    vector<string> letterCombinations(string digits) {

        // If input is empty, return empty result
        if (digits.length() == 0) {
            return result;
        }

        // Start recursion from index 0 with empty string
        backtrack(0, "", digits);

        return result;
    }

    // i = which digit we are currently processing
    // current = string formed so far
    void backtrack(int i, string current, string &digits) {

        // If we have chosen one character for every digit
        if (current.length() == digits.length()) {
            result.push_back(current);   // store the combination
            return;                      // stop this path
        }

        // Convert digit character to number
        int digit = digits[i] - '0';

        // Get all letters for this digit
        string letters = mapping[digit];

        // Try every possible letter
        for (int k = 0; k < letters.length(); k++) {

            char ch = letters[k];        // pick one letter

            // Add this letter and move to next digit
            backtrack(i + 1, current + ch, digits);
        }
    }
};
