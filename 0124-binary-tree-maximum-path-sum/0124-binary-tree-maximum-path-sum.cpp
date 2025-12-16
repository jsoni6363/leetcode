class Solution {
public:
    int maxPathSum(TreeNode* root) {
        // Initialize result with root value
        // (Important in case all values are negative)
        int res = root->val;

        // Start DFS traversal
        dfs(root, res);

        // Final answer stored in res
        return res;
    }

private:
    /**
     * dfs(root, res)
     * ----------------
     * Returns the maximum path sum that:
     * - starts at this node
     * - goes DOWNWARD (left OR right)
     * - can be extended by the parent
     *
     * Also updates 'res' with the best
     * "split path" found anywhere in the tree.
     */
    int dfs(TreeNode* root, int& res) {
        // Base case: empty node contributes 0
        if (!root) {
            return 0;
        }

        // Recursively compute best downward path from left child
        // If it is negative, ignore it (use 0 instead)
        int leftMax = max(dfs(root->left, res), 0);

        // Recursively compute best downward path from right child
        // If it is negative, ignore it
        int rightMax = max(dfs(root->right, res), 0);

        /**
         * Path that passes THROUGH this node
         * (can take both left and right)
         *
         *      left
         *       |
         *     root
         *       |
         *      right
         */
        int splitPath = root->val + leftMax + rightMax;

        // Update global maximum path sum
        res = max(res, splitPath);

        /**
         * Return the best path that can be extended upward
         * (parent can only take one direction)
         */
        return root->val + max(leftMax, rightMax);
    }
};
