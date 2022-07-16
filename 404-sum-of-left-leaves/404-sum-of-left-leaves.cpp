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
    int sum=0;
    
    bool leaf(TreeNode* root){
    	return root->left==NULL && root->right==NULL;
    }
    int sumOfLeftLeaves(TreeNode* root, bool leftleaf = false) {
        if(root==NULL) return 0;
        sumOfLeftLeaves(root->left,true);
        if(leftleaf && leaf(root)){  
            sum+=root->val;
         }
        sumOfLeftLeaves(root->right,false);
        return sum;
    }
    // int sumOfLeftLeaves(TreeNode* root){
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     int sum=0;
    //     while(!q.empty()){
    //         TreeNode* t=q.front();
    //         q.pop();
    //         if(t->left) {
    //             q.push(t->left);
    //             if(leaf(t->left))
    //             sum+=t->left->val;
    //         }
    //         if(t->right){
    //             q.push(t->right);
    //         }
    //     }
    //     return sum;
    // }
};