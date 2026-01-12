class Solution {
public:
    vector<string> letterCombinations(string digits) {

        // If input is empty, no combinations possible
        if (digits.size() == 0) return {};

        // This will store our final answer
        vector<string> res;
        res.push_back("");   // start with empty string

        // Mapping of digit to characters
        vector<string> mp = {
            "",     // 0 (not used)
            "",     // 1 (not used)
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        // Loop over each digit in input
        for (char d : digits) {

            vector<string> temp;  // to store new combinations

            // For every string formed so far
            for (string cur : res) {

                // Take all characters mapped to this digit
                for (char ch : mp[d - '0']) {

                    // Add character to current string
                    temp.push_back(cur + ch);
                }
            }

            // Update result with newly formed combinations
            res = temp;
        }

        return res;
    }
};
