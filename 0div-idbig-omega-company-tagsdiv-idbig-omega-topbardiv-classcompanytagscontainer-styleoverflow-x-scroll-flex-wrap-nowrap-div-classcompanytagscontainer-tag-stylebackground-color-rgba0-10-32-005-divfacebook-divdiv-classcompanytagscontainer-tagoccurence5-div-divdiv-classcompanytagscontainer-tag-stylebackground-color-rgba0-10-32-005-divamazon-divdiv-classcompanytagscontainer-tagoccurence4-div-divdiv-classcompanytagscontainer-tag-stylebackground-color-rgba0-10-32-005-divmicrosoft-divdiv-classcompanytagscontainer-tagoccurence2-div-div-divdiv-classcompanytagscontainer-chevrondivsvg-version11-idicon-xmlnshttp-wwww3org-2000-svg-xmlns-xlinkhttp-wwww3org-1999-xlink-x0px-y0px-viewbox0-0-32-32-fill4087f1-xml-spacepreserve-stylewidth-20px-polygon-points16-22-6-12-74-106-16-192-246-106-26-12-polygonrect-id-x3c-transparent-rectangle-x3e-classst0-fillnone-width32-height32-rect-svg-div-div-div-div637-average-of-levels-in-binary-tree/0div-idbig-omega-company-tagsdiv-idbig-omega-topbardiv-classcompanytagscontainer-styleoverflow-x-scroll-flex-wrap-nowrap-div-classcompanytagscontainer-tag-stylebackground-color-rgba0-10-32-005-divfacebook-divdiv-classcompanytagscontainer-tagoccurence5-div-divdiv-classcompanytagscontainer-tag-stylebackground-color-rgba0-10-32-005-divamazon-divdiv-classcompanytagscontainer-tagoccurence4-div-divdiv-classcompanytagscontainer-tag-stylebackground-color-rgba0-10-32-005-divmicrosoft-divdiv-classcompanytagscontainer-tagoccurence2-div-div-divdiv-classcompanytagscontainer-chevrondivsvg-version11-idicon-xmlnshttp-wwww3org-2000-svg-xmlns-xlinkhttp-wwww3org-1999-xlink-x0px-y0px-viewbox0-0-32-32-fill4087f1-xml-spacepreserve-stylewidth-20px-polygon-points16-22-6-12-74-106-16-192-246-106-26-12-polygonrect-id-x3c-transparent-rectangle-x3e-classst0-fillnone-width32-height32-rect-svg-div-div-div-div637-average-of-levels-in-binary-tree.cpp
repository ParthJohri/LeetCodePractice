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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            long long int sz=q.size(),s=q.size(),temp=0;
            while(sz--){
                TreeNode* t=q.front();
                q.pop();
                temp+=t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back((temp*1.0)/s);
        }
        return ans;
    }
};