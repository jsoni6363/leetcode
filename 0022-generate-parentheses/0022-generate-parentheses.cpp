class Solution {
public:
    vector<string> result;

    // backtrack function
    // current = string built so far
    // open = number of '(' used
    // close = number of ')' used
    // n = total pairs
    void backtrack(string current, int open, int close, int n) {

        // ✅ If length is 2*n, we formed a valid combination
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // ✅ We can add '(' if we still have some left
        if (open < n) {
            backtrack(current + "(", open + 1, close, n);
        }

        // ✅ We can add ')' only if it won't make string invalid
        if (close < open) {
            backtrack(current + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return result;
    }
};
