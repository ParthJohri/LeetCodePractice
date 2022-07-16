/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool leaf(TreeNode* root){
        return root->left==NULL&&root->right==NULL;
    }
    bool getPath(TreeNode* root,string s,vector<string>&arr){
        if(!root) return false;
        s+=to_string(root->val)+"->";
        if(leaf(root)) {
            arr.push_back(s.substr(0,s.length()-2));
            s=s.substr(0,s.length()-3);
            return false;
        }
        getPath(root->left,s,arr);
        getPath(root->right,s,arr);
        return false;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> arr;
        if(root==NULL) return arr;
        getPath(root,"",arr);
        return arr;
    }
};