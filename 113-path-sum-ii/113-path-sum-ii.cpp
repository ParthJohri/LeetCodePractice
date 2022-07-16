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
    void getPaths(TreeNode* root,vector<int> v, int sum,vector<vector<int>> &ans, int &tgsum){
        if(!root) return;
        v.push_back(root->val);
        sum+=root->val;
        if(sum==tgsum && leaf(root)){
            ans.push_back(v);
            sum-=v.back();
            v.pop_back();
        }
        getPaths(root->left,v,sum,ans,tgsum);
        getPaths(root->right,v,sum,ans,tgsum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        getPaths(root,vector<int>(),0,ans,targetSum);
        return ans;
    }
};