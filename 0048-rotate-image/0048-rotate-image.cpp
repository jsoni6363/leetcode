class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();   // matrix is n x n

        // Create a new matrix to store rotated result
        vector<vector<int>> rotated(n, vector<int>(n));

        // Traverse every cell of original matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // Place element at its new rotated position
                // Original position  -> Rotated position
                // (i, j)              -> (j, n - 1 - i)
                rotated[j][n - 1 - i] = matrix[i][j];
            }
        }

        // Copy rotated matrix back to original
        matrix = rotated;
    }
};
