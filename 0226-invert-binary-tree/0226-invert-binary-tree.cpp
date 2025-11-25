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

        if (!root) return nullptr;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {

            TreeNode* node = st.top();
            st.pop();

            // Swap children
            swap(node->left, node->right);

            // Push children to process later
            if (node->left)  st.push(node->left);
            if (node->right) st.push(node->right);
        }

        return root;
    }
};
