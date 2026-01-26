class Solution {
public:

    // Function to reverse one row
    void reverse(vector<int>& temp, int n){
        int a = 0, b = n - 1;

        // Standard two-pointer array reverse
        while(a < b){
            swap(temp[a], temp[b]);
            a++;
            b--;
        }
    }

    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();   // square matrix size

        // -----------------------------
        // STEP 1: Transpose the matrix
        // -----------------------------
        // Swap elements across main diagonal
        // (i, j) <-> (j, i)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // After transpose:
        // rows become columns, but order is not yet rotated

        // -----------------------------
        // STEP 2: Reverse each row
        // -----------------------------
        // This fixes the order to make it 90° clockwise
        for(int i = 0; i < n; i++){
            reverse(matrix[i], n);
        }
    }
};
