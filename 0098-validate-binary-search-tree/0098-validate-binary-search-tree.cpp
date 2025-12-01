class Solution {
public:

    // Main function to check if the tree is a Valid BST
    bool isValidBST(TreeNode* root) {

        // STEP 1: An empty tree is valid BST
        if (root == NULL) {
            return true;
        }

        // STEP 2: Create a queue to perform BFS traversal
        // We store each entry as: {node, leftBoundary, rightBoundary}
        queue<tuple<TreeNode*, long, long>> q;

        // STEP 3: Push the root node with the widest possible range
        // Initially: root is allowed to be between (-∞, +∞)
        q.push({root, LONG_MIN, LONG_MAX});

        // STEP 4: Process queue until it's empty
        while (q.size() > 0) {

            // STEP 5: Read the front tuple
            auto front = q.front();
            q.pop();

            TreeNode* node = get<0>(front);    // current node
            long left = get<1>(front);         // minimum allowed value for this node
            long right = get<2>(front);        // maximum allowed value for this node

            // STEP 6: Check if current node value respects the range given to it
            // Node must be strictly inside the boundaries, not equal to them
            if (node->val <= left || node->val >= right) {
                return false; // violation found → not a BST
            }

            // STEP 7: Push left child with updated boundary:
            // left boundary stays same
            // parent value becomes new RIGHT boundary for left subtree
            if (node->left != NULL) {
                q.push({node->left, left, node->val});
            }

            // STEP 8: Push right child with updated boundary:
            // parent value becomes new LEFT boundary for right subtree
            // right boundary stays same
            if (node->right != NULL) {
                q.push({node->right, node->val, right});
            }
        }

        // STEP 9: If we reached here, no rule was broken, so it is valid BST
        return true;
    }
};
