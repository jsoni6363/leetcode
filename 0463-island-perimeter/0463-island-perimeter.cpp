class Solution {
private:
    // Store grid locally so DFS can access it easily
    vector<vector<int>> grid;

    // To avoid revisiting the same land cell
    vector<vector<bool>> visited;

    int rows, cols;

    /*
        DFS FUNCTION
        ------------
        This function returns how much perimeter is contributed
        by the cell at position (i, j).
    */
    int dfs(int i, int j) {

        /*
            CASE 1: Out of grid bounds
            -------------------------
            If we move outside the grid,
            that means the land edge is exposed.
            => contributes 1 to perimeter
        */
        if (i < 0 || j < 0 || i >= rows || j >= cols) {
            return 1;
        }

        /*
            CASE 2: Water cell
            ------------------
            If the neighboring cell is water,
            the land edge touching water contributes 1
        */
        if (grid[i][j] == 0) {
            return 1;
        }

        /*
            CASE 3: Already visited land
            ----------------------------
            We have already processed this cell,
            so we should NOT count anything again.
        */
        if (visited[i][j]) {
            return 0;
        }

        /*
            CASE 4: Fresh land cell
            -----------------------
            Mark it visited and explore all 4 directions
        */
        visited[i][j] = true;

        /*
            Explore all four directions:
            - Right
            - Down
            - Left
            - Up

            Each recursive call returns
            how much perimeter that direction contributes
        */
        int right = dfs(i, j + 1);
        int down  = dfs(i + 1, j);
        int left  = dfs(i, j - 1);
        int up    = dfs(i - 1, j);

        // Total perimeter from this cell
        return right + down + left + up;
    }

public:
    int islandPerimeter(vector<vector<int>>& inputGrid) {

        // Store grid
        grid = inputGrid;
        rows = grid.size();
        cols = grid[0].size();

        // Initialize visited matrix
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        /*
            Find ANY land cell and start DFS
            There is guaranteed to be exactly one island
        */
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    // Start DFS from first land cell found
                    return dfs(i, j);
                }
            }
        }

        // If no land found (edge case, not really possible here)
        return 0;
    }
};
