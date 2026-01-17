class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();        // total rows
        int m = matrix[0].size();     // total columns

        // Extra variable to track if first column must be zero
        int col = 1;

        // ------------------------------------------------
        // STEP 1: Use first row & first column as markers
        // ------------------------------------------------
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(matrix[i][j] == 0) {

                    // Mark current row
                    matrix[i][0] = 0;

                    if(j != 0)
                        // Mark current column
                        matrix[0][j] = 0;
                    else
                        // Zero appeared in first column
                        col = 0;
                }
            }
        }

        // ------------------------------------------------
        // STEP 2: Update inner matrix (skip first row/col)
        // ------------------------------------------------
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {

                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // -----------------------------
        // STEP 3: Handle first row
        // -----------------------------
        if(matrix[0][0] == 0) {
            for(int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // -----------------------------
        // STEP 4: Handle first column
        // -----------------------------
        if(col == 0) {
            for(int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
