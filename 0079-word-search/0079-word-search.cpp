class Solution {
public:
    int ROWS, COLS;

    bool exist(vector<vector<char>>& board, string word) {

        ROWS = board.size();
        COLS = board[0].size();

        // Try starting DFS from every cell
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {

                // If the word can be formed starting here
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        // Word not found
        return false;
    }

    // DFS function
    // r, c -> current cell
    // i    -> index in word we need to match
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {

        // ✅ All characters matched
        if (i == word.size()) {
            return true;
        }

        // ❌ Stop if:
        // - Out of grid
        // - Character doesn't match
        // - Already visited (marked as '#')
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||
            board[r][c] != word[i] || board[r][c] == '#') {
            return false;
        }

        // Save current character
        char temp = board[r][c];

        // Mark cell as visited
        board[r][c] = '#';

        // Explore all 4 directions
        bool found =
            dfs(board, word, r + 1, c, i + 1) ||   // Down
            dfs(board, word, r - 1, c, i + 1) ||   // Up
            dfs(board, word, r, c + 1, i + 1) ||   // Right
            dfs(board, word, r, c - 1, i + 1);     // Left

        // Restore the original value (backtracking)
        board[r][c] = temp;

        return found;
    }
};
