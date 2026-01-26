class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int ROWS = matrix.size();        // number of rows in original matrix
        int COLS = matrix[0].size();     // number of columns in original matrix

        // Result matrix will have:
        // COLS rows and ROWS columns
        vector<vector<int>> res(COLS, vector<int>(ROWS));

        // Traverse each cell of original matrix
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {

                // Swap row and column index
                // original (r, c) -> transpose (c, r)
                res[c][r] = matrix[r][c];
            }
        }

        return res;
    }
};
