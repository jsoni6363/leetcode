class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        // Number of rows
        int n = matrix.size();

        // Number of columns
        int m = matrix[0].size();

        // Step 1: Create helper arrays to mark rows and columns
        // row[i] = 1 means row i should be zeroed
        // col[j] = 1 means column j should be zeroed
        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Step 2: Traverse the matrix and mark rows & columns
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // If current cell is zero,
                // mark its entire row and column
                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Step 3: Traverse again and update the matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // If this row OR column is marked,
                // set this cell to zero
                if(row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
