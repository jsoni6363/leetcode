class Solution {
public:
    int ROWS, COLS;

    // visited[r][c] tells whether this cell
    // is already used in the current DFS path
    vector<vector<bool>> visited;

    // Main function
    bool exist(vector<vector<char>>& board, string word) {

        ROWS = board.size();
        COLS = board[0].size();

        // Initialize visited matrix with false
        visited = vector<vector<bool>>(ROWS, vector<bool>(COLS, false));

        // Try starting DFS from every cell
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {

                // If word can be formed starting from (r, c)
                if (dfs(board, word, r, c, 0)) {
                    return true;
                }
            }
        }

        // Word not found anywhere
        return false;
    }

    // DFS function
    // r, c -> current cell
    // i    -> index of character in 'word' we need to match
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {

        // ✅ If all characters are matched
        if (i == word.length()) {
            return true;
        }

        // ❌ Stop if:
        // 1. Out of grid
        // 2. Current char doesn't match word[i]
        // 3. This cell is already used in this path
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||
            board[r][c] != word[i] || visited[r][c]) {
            return false;
        }

        // Mark this cell as visited (choose)
        visited[r][c] = true;

        // Explore all 4 directions
        bool found =
            dfs(board, word, r + 1, c, i + 1) ||  // Down
            dfs(board, word, r - 1, c, i + 1) ||  // Up
            dfs(board, word, r, c + 1, i + 1) ||  // Right
            dfs(board, word, r, c - 1, i + 1);    // Left

        // Unmark this cell (backtrack)
        visited[r][c] = false;

        return found;
    }
};
