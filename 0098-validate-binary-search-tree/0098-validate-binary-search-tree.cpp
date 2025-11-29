class Solution {
public:

    // Main function to start BST validation
    bool isValidBST(TreeNode* root) {

        // We call the helper function `valid()` on root
        // LONG_MIN = smallest possible number we can store
        // LONG_MAX = largest possible number we can store
        // This means root can initially be ANY value (no limits)
        return valid(root, LONG_MIN, LONG_MAX);
    }


    // Helper function to validate each node in a valid value range
    bool valid(TreeNode* node, long leftBoundary, long rightBoundary) {

        // STEP 1: If we reach a null node, that path is valid
        // (empty trees or end of branch doesn't violate any BST rule)
        if (node == NULL) {
            return true;
        }

        // STEP 2: Check if current node value lies strictly inside range
        // It must be:
        //       leftBoundary < node->val < rightBoundary
        // If not inside, return false because BST rule breaks
        if (leftBoundary >= node->val || node->val >= rightBoundary) {
            return false;
        }

        // STEP 3: Now validate left subtree with updated RIGHT limit = node->val
        // Left subtree must contain ONLY smaller values than current node
        bool checkLeft = valid(node->left, leftBoundary, node->val);

        // STEP 4: Now validate right subtree with updated LEFT limit = node->val
        // Right subtree must contain ONLY greater values than current node
        bool checkRight = valid(node->right, node->val, rightBoundary);

        // STEP 5: Both sides must be valid
        return checkLeft && checkRight;
    }
};
