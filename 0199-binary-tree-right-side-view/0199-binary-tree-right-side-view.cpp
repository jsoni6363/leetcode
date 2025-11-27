class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;  // stores final visible nodes
        queue<TreeNode*> q; // queue for BFS
        
        if(root) 
            q.push(root);  // Push root if it's not null
        
        while (!q.empty()) { // while queue still has nodes
            TreeNode* rightSide = nullptr; // stores rightmost node of current level
            int qLen = q.size(); // number of nodes in this level

            // Process exactly qLen nodes (one full level)
            for (int i = 0; i < qLen; i++) {
                TreeNode* node = q.front(); 
                q.pop();  // pop the node
                
                if (node) { // Only consider valid nodes
                    rightSide = node; // keep updating — last node ends up being rightmost

                    // Push children into queue for next level
                    if(node->left) 
                        q.push(node->left);
                    if(node->right) 
                        q.push(node->right);
                }
            }

            // After finishing the level, add the rightmost node if it exists
            if (rightSide) {
                res.push_back(rightSide->val);
            }
        }
        return res; 
    }
};
