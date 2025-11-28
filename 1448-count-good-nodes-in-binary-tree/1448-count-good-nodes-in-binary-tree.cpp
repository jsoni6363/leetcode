class Solution {
public:
    int goodNodes(TreeNode* root) {

        // STEP 1: result counter for good nodes
        int res = 0;

        // STEP 2: queue that stores node + max value in its root path
        queue<pair<TreeNode*, int>> q;

        // STEP 3: push root with the smallest possible max initially
        // This ensures the root node gets counted because nothing before it exists
        q.push({root, -INT_MAX});

        // STEP 4: process queue until empty
        while (q.size() > 0) {

            // STEP 5: take front element
            pair<TreeNode*, int> front = q.front();
            TreeNode* node = front.first;
            int maxSoFar = front.second;
            q.pop();

            // STEP 6: compare node value with max carried to it
            if (node->val >= maxSoFar) {
                // this node is good → increase count
                res = res + 1;
            }

            // STEP 7: update the max value for children path
            if (node->val > maxSoFar) {
                maxSoFar = node->val;
            }

            // STEP 8: push left child with updated max
            if (node->left != NULL) {
                q.push({node->left, maxSoFar});
            }

            // STEP 9: push right child with updated max
            if (node->right != NULL) {
                q.push({node->right, maxSoFar});
            }
        }

        // STEP 10: return total good nodes found
        return res;
    }
};
