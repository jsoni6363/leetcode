class Solution {
public:
    vector<int> res;  // This will store the final answer

    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0); // start DFS at depth = 0
        return res;
    }

    void dfs(TreeNode* node, int depth) {
        if (!node) 
            return; // Base case: if node is null, stop

        // If this level is not yet filled in res, add the current node
        if (res.size() == depth) {
            res.push_back(node->val);
            // Why? Because we're visiting right subtree first,
            // so the *first node visited at each depth* is always the rightmost one.
        }

        // Visit RIGHT child first, then LEFT child
        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
        // Order matters — right first ensures visibility from right side.
    }
};
