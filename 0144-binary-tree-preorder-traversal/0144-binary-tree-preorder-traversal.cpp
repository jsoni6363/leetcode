class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> preorder;  // this will store the preorder result

        // If tree is empty, just return empty vector
        if (root == NULL)
            return preorder;

        stack<TreeNode*> s;    // stack to simulate recursive calls
        s.push(root);          // start with the root node

        // Continue until stack becomes empty
        while (!s.empty()) {

            // Get the top element (current node)
            TreeNode* node = s.top();
            s.pop();

            // 1️⃣ PREORDER STEP: Visit the node (push its value)
            preorder.push_back(node->val);

            // 2️⃣ Push RIGHT CHILD FIRST  
            //    Why? Because stack is LIFO, so LEFT will be processed first.
            if (node->right != NULL)
                s.push(node->right);

            // 3️⃣ Push LEFT CHILD SECOND  
            if (node->left != NULL)
                s.push(node->left);
        }

        return preorder;
    }
};
