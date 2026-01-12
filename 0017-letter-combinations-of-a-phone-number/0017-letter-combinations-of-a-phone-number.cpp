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

        // Loop over each digit
        for (int i = 0; i < digits.length(); i++) {

            int digit = digits[i] - '0';  // convert char to number
            vector<string> temp;

            // Loop over all existing strings
            for (int j = 0; j < res.size(); j++) {

                string current = res[j];

                // Loop over all characters for this digit
                for (int k = 0; k < mp[digit].length(); k++) {

                    char ch = mp[digit][k];
                    temp.push_back(current + ch);
                }
            }

            // Update result
            res = temp;
        }

        return res;
    }
};
