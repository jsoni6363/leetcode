class Solution {
public:

    // This function deletes a node with value == key and returns the updated tree root
    TreeNode* deleteNode(TreeNode* root, int keyToDelete) {

        // STEP 1: If root is empty, nothing to delete, just return
        if (root == NULL) {
            return root;
        }

        // STEP 2: If the key is greater than current node value, move to right subtree
        if (keyToDelete > root->val) {
            // Recursive call to delete in right subtree
            // Attach the returned updated subtree back
            root->right = deleteNode(root->right, keyToDelete);
        }

        // STEP 3: If the key is smaller than current node value, move to left subtree
        if (keyToDelete < root->val) {
            // Recursive call to delete in left subtree
            // Attach returned updated subtree back
            root->left = deleteNode(root->left, keyToDelete);
        }

        // STEP 4: If key == current node value, this is the node we will delete
        if (keyToDelete == root->val) {

            // SUB–CASE 1:
            // If left child is NULL, replace node with right child directly
            if (root->left == NULL) {
                return root->right;
            }

            // SUB–CASE 2:
            // If right child is NULL, replace the node with left child directly
            if (root->right == NULL) {
                return root->left;
            }

            // SUB–CASE 3:
            // Node has 2 children → find smallest node in the right subtree (inorder successor)
            TreeNode* successor = root->right;

            // Keep going left to find the minimum in right subtree
            while (successor->left != NULL) {
                successor = successor->left;
                // This ensures we reach the smallest value node in the right subtree
            }

            // Copy successor value into current node (root)
            root->val = successor->val;

            // Delete the duplicate successor from the right subtree
            // We pass root->val because it was replaced by successor
            root->right = deleteNode(root->right, root->val);
        }

        // STEP 5: return the updated root
        return root;
    }
};
