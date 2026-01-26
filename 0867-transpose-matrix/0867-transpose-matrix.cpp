class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int ROWS = matrix.size();       // number of rows
        int COLS = matrix[0].size();    // number of columns

        // -----------------------------
        // CASE 1: Square matrix → in-place transpose
        // -----------------------------
        if (ROWS == COLS) {

            // We only traverse elements BELOW the diagonal
            // because diagonal elements stay same
            // and swapping whole matrix would double-swap.
            for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < r; c++) {

                    // Swap symmetric elements across diagonal
                    // (r, c) <-> (c, r)
                    swap(matrix[r][c], matrix[c][r]);
                }
            }

            // Same matrix is now transposed
            return matrix;
        }

        // -----------------------------
        // CASE 2: Rectangular matrix → create new matrix
        // -----------------------------
        vector<vector<int>> res(COLS, vector<int>(ROWS));

        // Copy elements with swapped indices
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {

                // (r, c) becomes (c, r)
                res[c][r] = matrix[r][c];
            }
        }

        return res;
    }
};
