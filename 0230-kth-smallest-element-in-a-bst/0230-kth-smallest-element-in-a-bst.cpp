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

    /*
     kthSmallest(...)
     ----------------
     Finds the kth smallest element in a BST
     using iterative inorder traversal.
    */
    int kthSmallest(TreeNode* root, int k) {

        // Stack to simulate recursion
        stack<TreeNode*> stack;

        // Pointer to traverse the tree
        TreeNode* curr = root;

        /*
         We continue looping as long as:
         - There are nodes in the stack
         OR
         - We still have nodes to explore
        */
        while (!stack.empty() || curr != nullptr) {

            // =========================
            // STEP 1: Go to the leftmost node
            // =========================

            /*
             Push all left children onto the stack.
             This mimics recursive inorder traversal.
            */
            while (curr != nullptr) {
                stack.push(curr);
                curr = curr->left;
            }

            // =========================
            // STEP 2: Process current node
            // =========================

            /*
             Pop the top node from the stack.
             This is the next node in sorted order.
            */
            curr = stack.top();
            stack.pop();

            // We have visited one node, so decrement k
            k--;

            /*
             If k becomes 0, this means:
             - We have reached the kth smallest element
             - Return its value immediately
            */
            if (k == 0) {
                return curr->val;
            }

            // =========================
            // STEP 3: Visit right subtree
            // =========================

            /*
             Move to the right child to continue inorder traversal.
            */
            curr = curr->right;
        }

        /*
         This return is just for safety.
         Problem guarantees k is valid.
        */
        return -1;
    }
};
