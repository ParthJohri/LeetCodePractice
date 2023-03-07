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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool even=true;
        while(!q.empty()){
            int sz=q.size();
            int val=even?0:INT_MAX;
            while(sz--){
                TreeNode* t=q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                if(even){
                    if(val>=t->val or t->val%2==0) return false;
                    val=t->val;
                }
                else{
                    if(val<=t->val or t->val%2!=0) return false;
                    val=t->val;
                }
            }
            even=!even;
        }
        return true;
    }
};