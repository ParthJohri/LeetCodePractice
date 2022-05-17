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
    int maxDepth(TreeNode* root) {
        // InOrder Traversal
        if(root==NULL) return 0;
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        return 1+max(lh,rh);
        // Level Order Traversal
        // queue<TreeNode*> q;
        // q.push(root);
        // int count=0;
        // if(root==NULL) return 0;
        // while(!q.empty())
        // {
        //     int size=q.size(); // Always use a variable to store the value of queue because here it is changing and q.size() will give wrong results
        //     ++count;
        //     for(int i=0;i<size;i++)
        //     {
        //         TreeNode* curr=q.front();
        //         q.pop();
        //         if(curr->left!=NULL)
        //             q.push(curr->left);
        //         if(curr->right!=NULL)
        //             q.push(curr->right);
        //     }
        // }
        // return count;
    }
};