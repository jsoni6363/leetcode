class Solution {
public:

    // DFS function that RETURNS the area of the current island
    int dfs(int i, int j, vector<vector<bool>>& vis, 
            vector<vector<int>>& grid, int n, int m) {

        // Step 1: Boundary check
        if(i < 0 || j < 0 || i >= n || j >= m)
            return 0;

        // Step 2: If already visited or water, stop and add 0 area
        if(vis[i][j] == true || grid[i][j] == 0)
            return 0;

        // Step 3: Mark current cell as visited
        vis[i][j] = true;

        // Step 4: Current cell contributes 1 area
        int area = 1;

        // Step 5: Add areas from all 4 directions
        area += dfs(i-1, j, vis, grid, n, m); // up
        area += dfs(i+1, j, vis, grid, n, m); // down
        area += dfs(i, j-1, vis, grid, n, m); // left
        area += dfs(i, j+1, vis, grid, n, m); // right

        return area;  // total area of this island
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int maxArea = 0;   // stores the largest island area

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Traverse grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // If unvisited land found, compute its area
                if(grid[i][j] == 1 && !vis[i][j]) {

                    int area = dfs(i, j, vis, grid, n, m); 
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
