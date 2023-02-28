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
    int recur(string& data){
        int pos=data.find(' ');
        int val=stoi(data.substr(0,pos));
        data=data.substr(pos+1);
        return val;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "#";
        return to_string(root->val)+" "+serialize(root->left)+" "+serialize(root->right);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserialize_helper(data);
    }
    TreeNode* deserialize_helper(string& data){
        if(data[0]=='#') {
            if(data.size()>1) data=data.substr(2);
            return NULL;
        }
        TreeNode* ans=new TreeNode(recur(data));
        ans->left=deserialize_helper(data);
        ans->right=deserialize_helper(data);
        return ans; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));