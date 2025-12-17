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
private:
void dfsSerialise(TreeNode* node,vector<string>& result){
    if(!node){
        result.push_back("N");
        return;
    }

    result.push_back(to_string(node->val));

    dfsSerialise(node->left,result);
    dfsSerialise(node->right,result);
}


TreeNode* dfsDeserialise(vector<string>& values,int& index){
        if(values[index]=="N"){
            index++;
            return NULL;
        }

        TreeNode* node=new TreeNode(stoi(values[index]));
        index++;

        node->left=dfsDeserialise(values,index);
        node->right=dfsDeserialise(values,index);
        return node;

}

vector<string> split(const string &s,char delim){
       vector<string> ele;

       stringstream ss(s);

       string item;

       while(getline(ss,item,delim)){
        ele.push_back(item);
       }

       return ele;
}

string join(const vector<string> &v,const string &delim){
    string ss="";
    for(int i=0;i<v.size();i++){
        if(i>0)
        ss+=delim;

        ss+=v[i];
    }
    return ss;
}

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> result;

        dfsSerialise(root,result);
        return join(result,",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> values=split(data,',');
        int index=0;
        return dfsDeserialise(values,index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));