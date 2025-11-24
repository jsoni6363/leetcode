class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        // Start BFS by pushing roots
        q1.push(p);
        q2.push(q);

        // Continue while both queues have nodes
        while (!q1.empty() && !q2.empty()) {

            // Process nodes level by level
            //from back cause size stays constant other wise increase na if from front 
            for (int i = q1.size(); i > 0; i--) {

                TreeNode* nodeP = q1.front(); q1.pop();
                TreeNode* nodeQ = q2.front(); q2.pop();

                // Case 1: both null → continue
                if (!nodeP && !nodeQ) continue;

                // Case 2: mismatch cases
                if (!nodeP || !nodeQ || nodeP->val != nodeQ->val)
                    return false;

                // Case 3: add children to queues
                q1.push(nodeP->left);
                q1.push(nodeP->right);

                q2.push(nodeQ->left);
                q2.push(nodeQ->right);
            }
        }

        // If both queues finished at same time → trees are the same
        return true;
    }
};
