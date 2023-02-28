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
    string recur(TreeNode* root,vector<TreeNode*>&ans,unordered_map<string,int>&m){
        if(root==NULL){
           return "";
        }
        string s=to_string(root->val)+" "+recur(root->left,ans,m)+" "+recur(root->right,ans,m);
        if(m[s]==1){
            ans.push_back(root);
        } 
        m[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        unordered_map<string,int> m;
        recur(root,ans,m);
        return ans;
    }
};