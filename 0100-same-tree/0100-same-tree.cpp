class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Stack stores pairs of nodes from both trees
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});

        while (!st.empty()) {

            // Take the top pair
            auto [node1, node2] = st.top();
            st.pop();

            // Case 1: both nodes are NULL → continue
            if (!node1 && !node2) continue;

            // Case 2: one is NULL or values differ → not same
            if (!node1 || !node2 || node1->val != node2->val)
                return false;

            // Case 3: push children to compare later
            st.push({node1->right, node2->right});
            st.push({node1->left, node2->left});
        }

        // All nodes matched → trees are the same
        return true;
    }
};
