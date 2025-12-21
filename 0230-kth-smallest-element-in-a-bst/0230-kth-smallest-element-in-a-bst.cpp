class Solution {
public:
    /*
     kthSmallest(...)
     ----------------
     Finds the kth smallest element in a BST
     using Morris inorder traversal.

     Time  : O(n)
     Space : O(1)
    */
    int kthSmallest(TreeNode* root, int k) {

        // Pointer used to traverse the tree
        TreeNode* curr = root;

        // To store the answer once found
        int answer = -1;

        // Traverse the tree
        while (curr != nullptr) {

            // =========================
            // CASE 1: No left child
            // =========================
            if (curr->left == nullptr) {

                /*
                 If there is no left subtree,
                 this node is visited immediately
                 in inorder traversal.
                */
                k--;

                // If k becomes 0, we found the answer
                if (k == 0) {
                    answer = curr->val;
                }

                // Move to right subtree
                curr = curr->right;
            }

            // =========================
            // CASE 2: Left child exists
            // =========================
            else {

                /*
                 Find inorder predecessor:
                 rightmost node in left subtree
                */
                TreeNode* pred = curr->left;

                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }

                // -------------------------
                // FIRST visit to curr
                // -------------------------
                if (pred->right == nullptr) {

                    /*
                     Create a temporary link
                     so we can return to curr
                     after finishing left subtree
                    */
                    pred->right = curr;

                    // Move to left subtree
                    curr = curr->left;
                }

                // -------------------------
                // SECOND visit to curr
                // -------------------------
                else {

                    /*
                     Left subtree already processed.
                     Remove the temporary link
                     to restore original tree.
                    */
                    pred->right = nullptr;

                    // Visit current node
                    k--;

                    if (k == 0) {
                        answer = curr->val;
                    }

                    // Move to right subtree
                    curr = curr->right;
                }
            }
        }

        // Return the stored answer
        return answer;
    }
};