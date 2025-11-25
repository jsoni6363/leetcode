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

        // If tree is empty, nothing to invert
        if (!root) return nullptr;

        queue<TreeNode*> q;
        q.push(root); // Start BFS from root

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            // Swap its children
            swap(node->left, node->right);

            // Add children to queue so we invert them later
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return root;
    }
};
