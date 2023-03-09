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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        int count=0;
        vector<int> v;
        while(!q.empty()){
            int sz=q.size(),x=0,n=sz;
            vector<int> level;
            while(sz--){
                TreeNode* t=q.front();
                q.pop();
                if(count%2){
                    t->val=v[x++];
                }
                if(t->left)  {
                q.push(t->left);
                level.push_back(t->left->val);}
                if(t->right) {
                q.push(t->right);
                level.push_back(t->right->val);}
            }
            if(level.empty()) break;
            ++count;
            if(count%2)
            reverse(level.begin(),level.end());   
            v=level;
        }
        return root;
    }
};