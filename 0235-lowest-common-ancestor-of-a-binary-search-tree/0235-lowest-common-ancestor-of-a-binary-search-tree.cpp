/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // BASE CONDITION 1:
        // If root is NULL → no node found → return NULL
        // BASE CONDITION 2:
        // If root is either p or q → we found one of the targets
        if (root == NULL || root == p || root == q)
            return root;

        // Recursively search in left subtree
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Recursively search in right subtree
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If left is NULL → both nodes (p,q) must be in right subtree
        if (left == NULL)
            return right;

        // If right is NULL → both nodes must be in left subtree
        else if (right == NULL)
            return left;

        // If both left and right are NOT NULL:
        // It means p was found in one subtree, q in the other.
        // So current root is their lowest common ancestor.
        else
            return root;
    }
};
