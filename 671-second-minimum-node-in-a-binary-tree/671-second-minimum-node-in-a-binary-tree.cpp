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
    void dfs(TreeNode* root,set<int> &v){
        if(root==NULL) return;
        dfs(root->left,v);
        v.insert(root->val);
        dfs(root->right,v);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> v;
        dfs(root,v);
        vector<int> ans;
        for(auto i:v){
            ans.push_back(i);
        }
        return ans.size()>=2?ans[1]:-1;
    }
};