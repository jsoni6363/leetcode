class Solution {
public:
    int maxDepth(TreeNode* root) {

        // Queue will store nodes level-by-level
        queue<TreeNode*> q;

        // If tree is empty → depth = 0
        if (root == nullptr)
            return 0;

        // Start BFS by adding root
        q.push(root);

        int depth = 0;  // this will count the number of levels

        // Repeat until all levels are processed
        while (!q.empty()) {

            // Number of nodes in the current level
            int levelSize = q.size();

            // Process all nodes of this level
            for (int i = 0; i < levelSize; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Add left child to queue
                if (node->left != nullptr)
                    q.push(node->left);

                // Add right child to queue
                if (node->right != nullptr)
                    q.push(node->right);
            }

            // We finished one whole level
            depth++;
        }

        return depth;
    }
};
