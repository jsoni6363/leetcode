class Solution {
public:

    // Main function that returns total good nodes in the tree
    int goodNodes(TreeNode* root) {
        // Start DFS from the root
        // We also pass root->val as the initial "maximum so far"
        // because on the way from root → root, max = root itself
        return dfs(root, root->val);
    }

private:

    // DFS function to visit every node and carry the max seen on the path
    int dfs(TreeNode* node, int maxSoFar) {

        // STEP 1: Stop recursion when node is null (end of a path)
        if (node == NULL) {
            return 0;
        }

        // STEP 2: Check if current node is a good node
        int count = 0;
        if (node->val >= maxSoFar) {
            // This means no node on the path before was greater than this
            // So we count this node as "good"
            count = 1;
        }

        // STEP 3: Update the maximum seen so far using current node value
        if (node->val > maxSoFar) {
            maxSoFar = node->val;
        }

        // STEP 4: Visit the left child with the updated max
        count = count + dfs(node->left, maxSoFar);

        // STEP 5: Visit the right child with the updated max
        count = count + dfs(node->right, maxSoFar);

        // STEP 6: Return total good nodes from this subtree
        return count;
    }
};
