class Solution {
public:
     //postorder cause Only after processing children do we know if the current node has become a leaf that should be deleted.
    // This function removes leaf nodes whose value equals 'target'
    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        // STEP 1: If the current root is null, nothing to clean, so return null
        if (root == NULL) {
            return NULL;
        }

        // STEP 2: Recursively clean the LEFT subtree first
        // The returned result is reattached to root->left
        root->left = removeLeafNodes(root->left, target);

        // STEP 3: Recursively clean the RIGHT subtree next
        // The returned result is reattached to root->right
        root->right = removeLeafNodes(root->right, target);

        // STEP 4: Now check the current node (root) itself
        // If it has no left child AND no right child, it is a LEAF
        // AND if its value equals the target, we must remove it
        if (root->left == NULL && root->right == NULL && root->val == target) {

            // STEP 5: Return NULL so that parent disconnects from this node
            return NULL;
        }

        // STEP 6: Otherwise, keep the node and return it upward
        return root;
    }
};
