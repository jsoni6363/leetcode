/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;

        if(!root) return "N,";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(node!=NULL){
                res += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
            else{
               res+= "N,";
            }
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string val;
        getline(ss,val,',');
  
        if(val=="N") return NULL;
        TreeNode* root= new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            if(!getline(ss,val,',')) break;
            if(val!="N"){
             node->left=new TreeNode(stoi(val));
             q.push(node->left);
            }
            if(!getline(ss,val,',')) break;
            if(val!="N"){
                node->right= new TreeNode(stoi(val));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));