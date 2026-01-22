class Solution {
public:

    // BFS function to visit all land cells connected to (i, j)
    void bfs(int i, int j, vector<vector<bool>>& vis, 
             vector<vector<char>>& grid, int n, int m) {

        // Queue for BFS traversal
        queue<pair<int,int>> q;

        // Mark the starting land cell as visited
        vis[i][j] = true;

        // Push the starting cell into the queue
        q.push({i, j});

        // Continue BFS until there are no more connected cells
        while(!q.empty()) {

            // Take the front cell from the queue
            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;

            // -------- Check UP --------
            if(row - 1 >= 0 && grid[row - 1][col] == '1' && !vis[row - 1][col]) {
                vis[row - 1][col] = true;          // mark visited
                q.push({row - 1, col});            // add to queue
            }

            // -------- Check DOWN --------
            if(row + 1 < n && grid[row + 1][col] == '1' && !vis[row + 1][col]) {
                vis[row + 1][col] = true;
                q.push({row + 1, col});
            }

            // -------- Check LEFT --------
            if(col - 1 >= 0 && grid[row][col - 1] == '1' && !vis[row][col - 1]) {
                vis[row][col - 1] = true;
                q.push({row, col - 1});
            }

            // -------- Check RIGHT --------
            if(col + 1 < m && grid[row][col + 1] == '1' && !vis[row][col + 1]) {
                vis[row][col + 1] = true;
                q.push({row, col + 1});
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int islands = 0;                 // stores number of islands
        int n = grid.size();             // number of rows
        int m = grid[0].size();          // number of columns

        // Visited matrix to track processed land cells
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Traverse every cell of the grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // If unvisited land is found, a new island starts
                if(grid[i][j] == '1' && !vis[i][j]) {

                    bfs(i, j, vis, grid, n, m);   // visit whole island
                    islands++;                   // count this island
                }
            }
        }

        // Return total number of islands
        return islands;
    }
};
