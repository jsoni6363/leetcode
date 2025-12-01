class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        // Stack to store nodes of the tree
        stack<TreeNode*> stk;

        // Stack to store visited flags for corresponding nodes in stk
        // false = first time seeing the node
        // true  = node is revisited after scheduling its children
        stack<bool> visit;

        // Result vector to store final postorder traversal
        vector<int> res;

        // Begin by pushing root into stack with visited = false
        stk.push(root);
        visit.push(false);

        // Run until there are no nodes left to process
        while (!stk.empty()) {

            // Extract the top node and its visited status
            TreeNode* cur = stk.top();
            bool v = visit.top();

            // Pop from both stacks to process it
            stk.pop();
            visit.pop();

            // If current node exists (not null)
            if (cur) {

                // If it's revisited (visited flag was true) → we process it now
                if (v) {
                    res.push_back(cur->val); 
                    // Because left and right children were already scheduled,
                    // we now safely add root to traversal output
                }

                // Else, this is the first time we see this node
                else {
                    // We want to process cur AFTER children, so push it back marked visited=true
                    stk.push(cur);
                    visit.push(true);

                    // Now schedule cur’s right and left children (visited=false)
                    // Right goes first so that left is processed before right (due to LIFO order)

                    stk.push(cur->right);
                    visit.push(false);

                    stk.push(cur->left);
                    visit.push(false);
                }
            }
        }

        // Return the complete postorder result
        return res;
    }
};
