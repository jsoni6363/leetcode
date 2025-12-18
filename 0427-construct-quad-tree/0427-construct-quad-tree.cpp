/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    /*
    This is the main function called by LeetCode.
    It starts building the Quad Tree from the entire grid.
    */
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();              // size of grid (n x n)
        return buildQuadTree(grid, n, 0, 0);
    }

private:
    /*
    buildQuadTree(...)
    ------------------
    Builds a Quad Tree for a square sub-grid.

    Parameters:
    - grid : original matrix
    - n    : size of current square
    - r    : starting row
    - c    : starting column
    */
    Node* buildQuadTree(vector<vector<int>>& grid, int n, int r, int c) {

        // Step 1: Check if all values in the current square are the same
        bool allSame = true;

        for (int i = 0; i < n && allSame; i++) {
            for (int j = 0; j < n; j++) {
                // If any cell differs from the first cell
                if (grid[r][c] != grid[r + i][c + j]) {
                    allSame = false;
                    break;
                }
            }
        }

        // Step 2: If all values are the same → create a leaf node
        if (allSame) {
            // grid[r][c] is either 0 or 1
            // val = true if 1, false if 0
            return new Node(grid[r][c] == 1, true);
        }

        // Step 3: If values are different → split into 4 quadrants
        int mid = n / 2;

        // Recursively build each quadrant
        Node* topLeft = buildQuadTree(grid, mid, r, c);
        Node* topRight = buildQuadTree(grid, mid, r, c + mid);
        Node* bottomLeft = buildQuadTree(grid, mid, r + mid, c);
        Node* bottomRight = buildQuadTree(grid, mid, r + mid, c + mid);

        // Step 4: Create an internal node with 4 children
        // val can be anything when isLeaf = false (problem allows it)
        return new Node(
            false,              // val (doesn't matter here)
            false,              // isLeaf = false
            topLeft,
            topRight,
            bottomLeft,
            bottomRight
        );
    }
};