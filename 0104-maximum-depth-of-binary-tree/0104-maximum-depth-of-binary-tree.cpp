class Solution {
public:
    int maxDepth(TreeNode* root) {

        // Base Case 1: empty tree has depth 0
        if (root == nullptr) {
            return 0;
        }

        // Recursively find depth of left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Depth of current node = 1 (current node) + larger subtree
        return 1 + max(leftDepth, rightDepth);
    }
};
