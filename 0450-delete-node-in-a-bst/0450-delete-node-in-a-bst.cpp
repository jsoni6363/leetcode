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
    TreeNode* deleteNode(TreeNode* root, int key) {

        // BASE CASE:
        // If tree is empty or we reach a NULL subtree → nothing to delete.
        if (!root) 
            return root;

        // STEP 1: Search for the node using BST property

        // If key is greater than current node's value,
        // it must be present in the RIGHT subtree.
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        // If key is smaller than current node's value,
        // it must be present in the LEFT subtree.
        else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        // Else, key == root->val → this is the node to delete.
        else {

            // CASE 1: No LEFT child
            // Replace this node with its RIGHT child
            // (right child may be NULL too → leaf deletion).
            if (!root->left) 
                return root->right;

            // CASE 2: No RIGHT child
            // Replace this node with its LEFT child.
            if (!root->right) 
                return root->left;

            // CASE 3: Node has BOTH left and right children.

            // Find the inorder successor:
            // → smallest value in the RIGHT subtree.
           else {
           // We are here when: key == root->val
           // AND root has BOTH left and right children.

           // STEP 3a: Find inorder successor (smallest in right subtree)
          TreeNode* cur = root->right;    // go to right subtree
           while (cur->left) {             // go as left as you can
           cur = cur->left;
          }
          // Now: cur points to the node with the smallest value in right subtree.

          // STEP 3b: Copy the successor's value into current node.
         // This "replaces" the value to be deleted with the next bigger one.
         root->val = cur->val;

          // STEP 3c: Delete the 'duplicate' node (which held successor value) 
         // from the right subtree.
        // We call deleteNode on right subtree to remove that node.
       root->right = deleteNode(root->right, root->val);
         }
        }
        // Return the (possibly updated) root pointer for this subtree.
        return root;
    }
};
