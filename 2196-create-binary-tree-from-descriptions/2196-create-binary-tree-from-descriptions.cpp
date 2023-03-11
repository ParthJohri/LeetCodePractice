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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        TreeNode* root;
        map<int,TreeNode*> m;
        int r=0;
        for(auto i:descriptions){
            int par=i[0],child=i[1],l=i[2];
            if(m.count(par)==0){
                TreeNode* p=new TreeNode(par);
                m[par]=p;
                r^=par;
            }
            if(m.count(child)==0){
                TreeNode* c=new TreeNode(child);
                m[child]=c;
                r^=child;
            }
        }
        for(auto i:descriptions){
            int par=i[0],child=i[1],l=i[2];
            if(l){
                m[par]->left=m[child];
            }
            else{
                m[par]->right=m[child];
            }
            r^=child;
        }
        root=m[r];
        return root;
    }
};