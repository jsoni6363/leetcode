class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        stack<TreeNode*> s;         // This will store nodes while we go left
        vector<int> inorder;        // Final inorder result
        TreeNode* node = root;      // Start from the root

        // We will run until:
        // 1. The stack still has nodes
        // OR
        // 2. We still have nodes to explore (node != NULL)
        //
        // So instead of `while(true)`, we can use:
        //   while (node != NULL || !s.empty())
        //
        // This is the BEST and CLEANEST condition.
        while (true) {

            // 1️⃣ Go as LEFT as possible
            if (node != NULL) {
                s.push(node);        // Save current node
                node = node->left;   // Move to left child
            }

            // 2️⃣ If node reaches NULL, we must backtrack using the stack
            else {

                // If stack is empty → we are completely done
                if (s.empty() == true)
                    break;

                // Pop the last left-visited node
                node = s.top();
                s.pop();

                // Visit the node (Inorder step)
                inorder.push_back(node->val);

                // Move to RIGHT subtree
                node = node->right;
            }
        }

        return inorder;
    }
};
