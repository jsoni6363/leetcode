class Solution {
public:

    // Checks whether a parentheses string is valid
    bool valid(const string& s) {
        int open = 0;

        for (char c : s) {
            if (c == '(')
                open++;      // opening bracket
            else
                open--;      // closing bracket

            // If at any time close > open → invalid
            if (open < 0) return false;
        }

        // At the end, all opens must be closed
        return open == 0;
    }

    // DFS to generate all possible strings
    void dfs(string s, vector<string>& res, int n) {

        // If length becomes 2*n, check validity
        if (s.length() == 2 * n) {
            if (valid(s)) {
                res.push_back(s);
            }
            return;
        }

        // Always try adding '('
        dfs(s + '(', res, n);

        // Always try adding ')'
        dfs(s + ')', res, n);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("", res, n);
        return res;
    }
};
