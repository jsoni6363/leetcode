class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;                   // To store nodes in Root->Right->Left order
        stack<TreeNode*> stack;            // Stack used for backtracking
        TreeNode* cur = root;              // Pointer to traverse tree

        // Continue while there is a node to explore OR stack has nodes to backtrack to
        while (cur || !stack.empty()) {

            // 🔹 Case 1: We are going down the RIGHT side
            if (cur) {
                res.push_back(cur->val);   // Store root first (but this is reversed order)
                stack.push(cur);           // Remember this node for later when going left
                cur = cur->right;          // Move right first
            }

            // 🔸 Case 2: cur is NULL, means right branch is exhausted, so BACKTRACK
            else {
                cur = stack.top();         // Come back to last stored node
                stack.pop();               // Remove it from stack since we are processing its left now
                cur = cur->left;           // Switch to left subtree now
            }
        }

        // Now res contains: Root → Right → Left
        // Reverse it so it becomes: Left → Right → Root (POSTORDER)
        reverse(res.begin(), res.end());

        return res; // Return final postorder traversal
    }
};
