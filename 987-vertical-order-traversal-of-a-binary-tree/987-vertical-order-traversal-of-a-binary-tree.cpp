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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto n=q.front();
            q.pop();
            TreeNode* curr=n.first;
            int x=n.second.first;
            int y=n.second.second;
            m[x][y].insert(curr->val);
            if(curr->left)
                q.push({curr->left,{x-1,y+1}});
            if(curr->right)
                q.push({curr->right,{x+1,y+1}});
        }
        vector<vector<int>> ans;
        for(auto p:m)
        {
            vector<int> col;
            for(auto c:p.second)
            {
                col.insert(col.end(),c.second.begin(),c.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};