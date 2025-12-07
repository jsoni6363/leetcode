class Solution {
    // 'res' stores the maximum path sum we find in the whole tree.
    // We initialize it with the smallest possible integer so any valid path will be larger.
    int res = INT_MIN;

    /**
     * getMax(root)
     * ----------------------------
     * This function returns the best **downward path sum** starting at 'root'
     * A downward path means:
     *   - It must start at this node
     *   - It can go down either left OR right (not both, because that would form a branch)
     *   - If taking the path makes the sum negative, we return 0 instead (ignore that path)
     *
     * Intuition:
     *   We ask:
     *     "If my parent wants to form a path including me, what is the max sum
     *      I can contribute in ONE single direction?"
     */
    int getMax(TreeNode* root) {
        if (root == nullptr) {
            // If tree/subtree is empty, it contributes 0 to the path sum
            return 0;
        }

        // Recursively find max downward path from left child
        int left = getMax(root->left);

        // Recursively find max downward path from right child
        int right = getMax(root->right);

        // Compute best path we can form including current node and one side (whichever is greater)
        int path = root->val + max(left, right);

        // If 'path' is negative, return 0 because it's better not to take this route.
        // Else return 'path' so parent can use it.
        return max(0, path);
    }

    /**
     * dfs(root)
     * ----------------------------
     * This function visits every node and treats it as a possible **center / highest point**
     * of a full path that can go:
     *
     *      left subtree ↓
     *           \
     *          root (center)
     *           /
     *      right subtree ↓
     *
     * This full path sum = root->val + left contribution + right contribution
     *
     * Then we update our global answer: res = maximum of all such center paths.
     *
     * IMPORTANT:
     *   The full center path is only for checking answer, we do NOT return it upward.
     *   We only return single-side paths in getMax().
     */
    void dfs(TreeNode* root) {
        if (root == nullptr) {
            // If node is null, stop recursion
            return;
        }

        // Compute best downward path sum we can take from left child (if positive)
        int left = getMax(root->left);

        // Compute best downward path sum we can take from right child (if positive)
        int right = getMax(root->right);

        // Check the best "centered" path including both sides and update result if larger
        res = max(res, root->val + left + right);

        // Continue DFS to compute answer for left subtree
        dfs(root->left);

        // Continue DFS to compute answer for right subtree
        dfs(root->right);
    }

public:
    /**
     * maxPathSum(root)
     * ----------------------------
     * This is the main function LeetCode calls.
     * It triggers DFS and finally returns the stored maximum.
     */
    int maxPathSum(TreeNode* root) {
        dfs(root);  // Start traversal from root
        return res; // After full traversal, res contains max possible path sum
    }
};