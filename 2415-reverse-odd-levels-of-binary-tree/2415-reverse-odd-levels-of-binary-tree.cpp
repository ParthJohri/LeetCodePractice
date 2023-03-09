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
    void dfs(TreeNode* rootleft,TreeNode* rootright, int level){
        if(!rootleft or !rootright) return;
        if(level%2==0) swap(rootleft->val,rootright->val);
        dfs(rootleft->left,rootright->right,level+1);
        dfs(rootleft->right,rootright->left,level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL) return NULL;
        dfs(root->left,root->right,0);
        return root;
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