class Solution {
    // This will store the maximum path sum found anywhere in the tree
    int res = INT_MIN;

    /**
     * getMax(root)
     * ----------------
     * Returns the maximum sum of a path that:
     * - starts at 'root'
     * - goes downward (left OR right)
     * - can be extended by the parent
     *
     * IMPORTANT:
     * If the path sum becomes negative, we return 0
     * because taking a negative path only reduces the total.
     */
    int getMax(TreeNode* root) {
        // Base case: empty node contributes 0
        if (!root) return 0;

        // Recursively get best downward path from left subtree
        int left = getMax(root->left);

        // Recursively get best downward path from right subtree
        int right = getMax(root->right);

        // Choose the better side and include current node
        int path = root->val + std::max(left, right);

        // If path becomes negative, ignore it
        return std::max(0, path);
    }

    /**
     * dfs(root)
     * ----------
     * Traverses every node and checks the best path
     * that uses this node as the "highest point"
     *
     * Here the path can:
     * left subtree → root → right subtree
     */
    void dfs(TreeNode* root) {
        if (!root) return;

        // Best downward contribution from left child
        int left = getMax(root->left);

        // Best downward contribution from right child
        int right = getMax(root->right);

        // Path that passes THROUGH current node
        int currentPath = root->val + left + right;

        // Update global maximum path sum
        res = std::max(res, currentPath);

        // Continue DFS traversal
        dfs(root->left);
        dfs(root->right);
    }

public:
    int maxPathSum(TreeNode* root) {
        // Start DFS traversal
        dfs(root);

        // Final answer stored in res
        return res;
    }
};
