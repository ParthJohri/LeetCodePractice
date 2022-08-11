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
    vector<int> ans;
    void dfs(TreeNode* root){
        if(root==NULL) return;
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> m;
        vector<int> v;
        dfs(root);
        int mx=INT_MIN;
        for(auto i:ans){
            m[i]++;
            mx=max(m[i],mx);
        }
        for(auto i:m){
            if(i.second==mx){
                v.push_back(i.first);
            }
        }
        return v;
    }
};