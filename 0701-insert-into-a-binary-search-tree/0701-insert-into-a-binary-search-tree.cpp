class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        // BASE CASE:
        // If we reach a NULL position, that means
        // this is the correct empty spot where the new value should go.
        // So create and return a new node.
        if (!root) {
            return new TreeNode(val);
        }

        // RECURSIVE CASE:
        // If the value to insert is GREATER than the current node,
        // we must go to the RIGHT subtree.
        if (val > root->val) {

            // Recursively insert into right subtree
            // and update the right child pointer.
            root->right = insertIntoBST(root->right, val);
        }

        // Otherwise, val is LESS than or EQUAL to root->val,
        // so we go to the LEFT subtree.
        else {

            // Recursively insert into left subtree
            // and update the left child pointer.
            root->left = insertIntoBST(root->left, val);
        }

        // Return the unchanged root pointer
        // so that parent nodes can reconnect properly.
        return root;
    }
};
