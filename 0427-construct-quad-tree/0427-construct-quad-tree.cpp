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
private:

    /*
     Shared leaf nodes
     -----------------
     These two nodes represent:
     - a leaf with value 0
     - a leaf with value 1

     They are created ONCE and reused everywhere.
     This saves memory because we don't create
     duplicate leaf nodes again and again.
    */
    Node* falseLeaf = new Node(false, true); // represents value 0
    Node* trueLeaf  = new Node(true, true);  // represents value 1

public:

    /*
     construct(...)
     --------------
     Entry point called by LeetCode.

     Starts building the Quad Tree for the entire grid,
     beginning at the top-left corner (0,0).
    */
    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0);
    }

private:

    /*
     dfs(grid, n, r, c)
     ------------------
     Builds a Quad Tree for a square region of size n x n.

     Parameters:
     - grid : original matrix
     - n    : size of current square
     - r    : starting row
     - c    : starting column
    */
    Node* dfs(vector<vector<int>>& grid, int n, int r, int c) {

        // =========================
        // BASE CASE
        // =========================

        /*
         If n == 1:
         - The region is 1 x 1
         - It contains only ONE cell
         - A single cell is always uniform

         Instead of creating a new leaf node,
         we reuse one of the shared leaf nodes.
        */
        if (n == 1) {
            return grid[r][c] == 1 ? trueLeaf : falseLeaf;
        }

        // =========================
        // SPLIT THE REGION
        // =========================

        /*
         Divide the current region into 4 equal parts.

         n is always a power of 2, so n/2 is safe.
        */
        n /= 2;

        /*
         Recursively build Quad Trees for all 4 quadrants.
        */
        Node* topLeft     = dfs(grid, n, r, c);
        Node* topRight    = dfs(grid, n, r, c + n);
        Node* bottomLeft  = dfs(grid, n, r + n, c);
        Node* bottomRight = dfs(grid, n, r + n, c + n);

        // =========================
        // MERGE STEP (KEY OPTIMIZATION)
        // =========================

        /*
         After building the 4 children, check:

         1. Are ALL children leaf nodes?
         2. Do ALL children have the SAME value?

         If yes:
         - The entire region is uniform
         - We do NOT create a new node
         - We reuse one existing leaf node
        */
        if (topLeft->isLeaf && topRight->isLeaf &&
            bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val &&
            topLeft->val == bottomLeft->val &&
            topLeft->val == bottomRight->val) {

            /*
             Returning topLeft is safe because:
             - All 4 children are leaf nodes
             - All 4 have the same value
             - So they are identical

             This saves memory.
            */
            return topLeft;
        }

        // =========================
        // INTERNAL NODE
        // =========================

        /*
         If we reach here:
         - The region is NOT uniform
         - We CANNOT merge the children
         - This node becomes an INTERNAL node

         isLeaf = false → has children
         val = false → ignored for internal nodes
        */
        return new Node(
            false,                  // val (irrelevant)
            false,                  // isLeaf
            topLeft,
            topRight,
            bottomLeft,
            bottomRight
        );
    }
};
