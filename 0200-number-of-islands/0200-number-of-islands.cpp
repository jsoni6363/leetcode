class Solution {
public:

    // DFS function to visit all connected land cells
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid, int n, int m) {
        
        // Step 1: Boundary check
        if(i < 0 || j < 0 || i >= n || j >= m)
            return;

        // Step 2: If already visited or water, stop
        if(vis[i][j] == true || grid[i][j] == '0')
            return;

        // Step 3: Mark current cell as visited
        vis[i][j] = true;

        // Step 4: Visit all 4 directions
        dfs(i-1, j, vis, grid, n, m); // up
        dfs(i+1, j, vis, grid, n, m); // down
        dfs(i, j-1, vis, grid, n, m); // left
        dfs(i, j+1, vis, grid, n, m); // right
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();

        // Visited array
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Traverse the grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // If unvisited land found → new island
                if(grid[i][j] == '1' && vis[i][j] == false) {
                    dfs(i, j, vis, grid, n, m);  // visit whole island
                    islands++;                 // count island
                }
            }
        }

        return islands;
    }
};
