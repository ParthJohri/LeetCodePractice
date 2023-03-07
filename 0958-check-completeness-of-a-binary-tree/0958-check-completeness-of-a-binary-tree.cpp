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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    bool isCompleteTree(TreeNode* root) {
        int h=height(root),count=0;
        if(h==1) return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            count++;
            int sz=q.size();
            if(count!=h and (int)pow(2,count-1)!=sz) return false;
            else if(count==h and ((int)pow(2,count-1)<sz or sz<1)) return false;
            bool flag=false;
            while(sz--){
                TreeNode* t=q.front();
                q.pop();
                if(t->left){
                    if(flag) return false;
                    q.push(t->left);
                }
                else flag=true;
                if(t->right){
                    if(flag) return false;
                    q.push(t->right);
                }
                else flag=true;
            }
        }
        return true;
    }
};