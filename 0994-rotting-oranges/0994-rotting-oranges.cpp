class Solution {
private:
    // Direction vectors for 4 neighbors (up, right, down, left)
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    
    // Helper function to check if a cell is within grid boundaries
    bool isValid(int i, int j, int n, int m) {
        if (i < 0 || i >= n) return false;
        if (j < 0 || j >= m) return false;
        return true;
    }
    
public:
    // Function to calculate minutes required for all oranges to rot
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int time = 0;      // Tracks time taken
        int total = 0;     // Total oranges (fresh + rotten)
        int count = 0;     // Rotten oranges processed

        queue<pair<int, int>> q; // BFS queue

        // Step 1: Traverse the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) total++;   // Count all oranges
                if (grid[i][j] == 2) {
                    q.push({i, j}); // Push rotten oranges into queue
                }
            }
        }

        // Step 2: Perform BFS
        while (!q.empty()) {
            int k = q.size(); // Number of rotten oranges at current level
            count += k;       // Update count

            while (k--) {
                auto cell = q.front();
                q.pop();

                int row = cell.first;
                int col = cell.second;

                // Traverse 4 neighbors
                for (int i = 0; i < 4; i++) {
                    int nRow = row + delRow[i];
                    int nCol = col + delCol[i];

                    // If neighbor is valid and fresh, rot it
                    if (isValid(nRow, nCol, n, m) && grid[nRow][nCol] == 1) {
                        grid[nRow][nCol] = 2;
                        q.push({nRow, nCol});
                    }
                }
            }
            if (!q.empty()) time++; // Increase time if new oranges rotted
        }

        return (total == count) ? time : -1; // If all rotted return time, else -1
    }
};