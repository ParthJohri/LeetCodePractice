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
        deque<pair<TreeNode*,int>> q;
        q.push_back({root,0});
        int mx=1;
        while(!q.empty()){
            int sz=q.size();
            int mmin=q.back().second;
            for(int i=0;i<sz;i++){
                pair<TreeNode*,int> t={q.front().first,q.front().second};
                int curr=q.front().second-mmin;
                q.pop_front();
                if(t.first->left) {
                    q.push_back({t.first->left,2*curr+1}); 
                }
                if(t.first->right) {
                    q.push_back({t.first->right,2*curr+2}); 
                }
            }
            // cout<<q.back().second-q.front().second+1<<endl;
            if(q.empty())
                break;
            mx=max(mx,q.back().second-q.front().second+1);
        }
        return mx;
    }
};