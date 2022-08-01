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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int mx=1;
        while(!q.empty()){
            int sz=q.size();
            int first,last;
            int mmin=q.front().second;
            for(int i=0;i<sz;i++){
                TreeNode* t=q.front().first;
                int curr=q.front().second-mmin;
                q.pop();
                if(i==0)
                first=curr;
                if(i==sz-1)
                last=curr;
                if(t->left) {
                    q.push({t->left,2*1ll*curr+1}); 
                }
                if(t->right) {
                    q.push({t->right,2*1ll*curr+2}); 
                }
            }
            mx=max(mx,last-first+1);
        }
        return mx;
    }
};