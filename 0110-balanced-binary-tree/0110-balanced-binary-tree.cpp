/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:

    // Function to return the height of a subtree
    int height(TreeNode* node) {

        // If the subtree is empty, height = 0
        if (node == NULL) 
            return 0;

        // Height of current node =
        // 1 + maximum height of its left or right child
        return 1 + max(height(node->left), height(node->right));
    }


    bool isBalanced(TreeNode* root) {

        // Empty tree is balanced
        if (root == NULL)
            return true;

        // Get height of left and right subtree
        int lh = height(root->left);
        int rh = height(root->right);

        // If height difference is more than 1 → not balanced
        if (abs(lh - rh) > 1)
            return false;

        // Check if left subtree is balanced
        bool left = isBalanced(root->left);

        // Check if right subtree is balanced
        bool right = isBalanced(root->right);

        // If any subtree is not balanced → return false
        if (!left || !right)
            return false;

        // Otherwise tree is balanced
        return true;
    }
};
