class Solution {
public:

    // BFS function to calculate area of the island starting from (i, j)
    int bfs(int i, int j, vector<vector<bool>>& vis, 
            vector<vector<int>>& grid, int n, int m) {

        // Queue for BFS traversal
        queue<pair<int,int>> q;

        // Mark starting land cell as visited
        vis[i][j] = true;

        // Push starting cell into queue
        q.push({i, j});

        int area = 1;   // starting cell contributes 1 to area

        // Continue BFS until queue is empty
        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;

            // -------- Check UP --------
            if(row - 1 >= 0 && grid[row - 1][col] == 1 && !vis[row - 1][col]) {
                vis[row - 1][col] = true;
                q.push({row - 1, col});
                area++;   // increase area
            }

            // -------- Check DOWN --------
            if(row + 1 < n && grid[row + 1][col] == 1 && !vis[row + 1][col]) {
                vis[row + 1][col] = true;
                q.push({row + 1, col});
                area++;
            }

            // -------- Check LEFT --------
            if(col - 1 >= 0 && grid[row][col - 1] == 1 && !vis[row][col - 1]) {
                vis[row][col - 1] = true;
                q.push({row, col - 1});
                area++;
            }

            // -------- Check RIGHT --------
            if(col + 1 < m && grid[row][col + 1] == 1 && !vis[row][col + 1]) {
                vis[row][col + 1] = true;
                q.push({row, col + 1});
                area++;
            }
        }

        // Return total area of this island
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int maxArea = 0;   // stores maximum island area

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // Traverse each cell of the grid
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // If unvisited land found, calculate its area
                if(grid[i][j] == 1 && !vis[i][j]) {

                    int area = bfs(i, j, vis, grid, n, m);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
