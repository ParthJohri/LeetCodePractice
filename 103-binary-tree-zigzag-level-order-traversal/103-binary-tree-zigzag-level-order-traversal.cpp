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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        q.push(root);
        bool flag=true; // flag==true L->R
        while(!q.empty())
        {
            int size=q.size();
            vector<int> level(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                int index=flag?i:size-1-i;
                level[index]=curr->val;
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            flag=!flag; // flag==false R->L
            ans.push_back(level);
        }
        return ans;
    }
};