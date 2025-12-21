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
     construct(...)
     --------------
     This is the main function called by LeetCode.

     It starts building the Quad Tree for the entire grid.
     - grid.size() gives the length of the grid (n x n)
     - (0, 0) is the top-left corner of the grid
    */
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }

private:

    /*
     dfs(grid, n, r, c)
     ------------------
     Builds a Quad Tree node for a square region of the grid.

     Parameters:
     - grid : the original 2D matrix
     - n    : size of the current square (n x n)
     - r    : starting row of the square
     - c    : starting column of the square
    */
    Node* dfs(vector<vector<int>>& grid, int n, int r, int c) {

        // =========================
        // BASE CASE
        // =========================

        /*
         If n == 1, the current region is a 1 x 1 square.
         This means:
         - There is only ONE cell
         - A single cell is always uniform
         - So we create a LEAF node
        */
        if (n == 1) {

            /*
             grid[r][c] is either 0 or 1.

             grid[r][c] == 1  → true
             grid[r][c] == 0  → false

             We pass this as the 'val' of the node.

             isLeaf = true because this node represents
             a single uniform value.
            */
            return new Node(grid[r][c] == 1, true);
        }

        // =========================
        // RECURSIVE DIVISION
        // =========================

        /*
         Since the region is larger than 1 x 1,
         we divide it into 4 equal parts.

         n is always a power of 2,
         so n / 2 is always an integer.
        */
        int mid = n / 2;

        /*
         Recursively build Quad Trees for all 4 quadrants:

         topLeft     → starts at (r, c)
         topRight    → starts at (r, c + mid)
         bottomLeft  → starts at (r + mid, c)
         bottomRight → starts at (r + mid, c + mid)
        */
        Node* topLeft = dfs(grid, mid, r, c);
        Node* topRight = dfs(grid, mid, r, c + mid);
        Node* bottomLeft = dfs(grid, mid, r + mid, c);
        Node* bottomRight = dfs(grid, mid, r + mid, c + mid);

        // =========================
        // MERGE STEP (IMPORTANT)
        // =========================

        /*
         After building all 4 children, we check:

         1. Are all 4 children LEAF nodes?
         2. Do all 4 children have the SAME value?

         If yes:
         - This means the entire region is uniform
         - We can merge them into ONE leaf node
        */
        if (topLeft->isLeaf && topRight->isLeaf &&
            bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val &&
            topLeft->val == bottomLeft->val &&
            topLeft->val == bottomRight->val) {

            /*
             Create and return a NEW leaf node.

             val = topLeft->val (all are same)
             isLeaf = true (merged into one)
            */
            return new Node(topLeft->val, true);
        }

        // =========================
        // INTERNAL NODE
        // =========================

        /*
         If we reach here:
         - The region is NOT uniform
         - We CANNOT merge the children
         - So this node becomes an INTERNAL node

         isLeaf = false → because it has children
         val = false → value does NOT matter for internal nodes
         (only children contain real data)
        */
        return new Node(
            false,                 // val (ignored)
            false,                 // isLeaf
            topLeft,
            topRight,
            bottomLeft,
            bottomRight
        );
    }
};
