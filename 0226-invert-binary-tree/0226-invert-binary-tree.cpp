/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        // Base case: empty tree
        if (!root) return nullptr;

        // Swap children
        swap(root->left, root->right);

        // Recursively invert subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root; // Return the root after inversion
    }
};
