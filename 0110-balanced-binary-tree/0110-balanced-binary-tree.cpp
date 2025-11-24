class Solution {
public:

    // Function to compute the height of a subtree
    int height(TreeNode* node) {

        // Base case: empty subtree has height 0
        if (node == NULL)
            return 0;

        // Height = 1 (current node) + height of larger subtree
        return 1 + max(height(node->left), 
                       height(node->right));
    }

    // Function to check if a tree is height-balanced
    bool isBalanced(TreeNode* root) {

        // Base case: an empty tree is balanced
        if (root == NULL)
            return true;

        // Compute the height of left and right subtrees
        int lh = height(root->left);
        int rh = height(root->right);

        // If height difference is more than 1 → NOT balanced
        if (abs(lh - rh) > 1)
            return false;

        // Recursively check if left subtree is balanced
        bool leftBalanced = isBalanced(root->left);

        // Recursively check right subtree
        bool rightBalanced = isBalanced(root->right);

        // Entire tree is balanced only if both subtrees are balanced
        return leftBalanced && rightBalanced;
    }
};
