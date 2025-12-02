/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    // cache[node] = maximum money we can rob from the subtree rooted at 'node'
    unordered_map<TreeNode*, int> cache;

public:
    int rob(TreeNode* root) {
        // For a null node (no house), the maximum money is 0.
        cache[nullptr] = 0;

        // Start the recursion from the root node.
        return dfs(root);
    }

private:
    int dfs(TreeNode* root) {
        // If we already computed the answer for this node,
        // return it directly from the cache (no need to recompute).
        if (cache.find(root) != cache.end()) {
            return cache[root];
        }

        // ---- Option 1: Rob this node (root) ----
        // Start with the money in the current house.
        int takeRoot = root->val;

        // If there is a left child, we cannot rob it,
        // but we can try to rob its children (grandchildren of root).
        if (root->left) {
            takeRoot += dfs(root->left->left);  // left-left grandchild
            takeRoot += dfs(root->left->right); // left-right grandchild
        }

        // Similarly for the right child: skip it but consider its children.
        if (root->right) {
            takeRoot += dfs(root->right->left);  // right-left grandchild
            takeRoot += dfs(root->right->right); // right-right grandchild
        }

        // ---- Option 2: Do NOT rob this node ----
        // If we skip this node, we are free to choose the best from its children.
        int skipRoot = dfs(root->left) + dfs(root->right);

        // The best answer for this node is the maximum of the two options.
        int best = max(takeRoot, skipRoot);

        // Store the answer in the cache so we don't recompute it later.
        cache[root] = best;

        // Return the best result for this subtree.
        return best;
    }
};
