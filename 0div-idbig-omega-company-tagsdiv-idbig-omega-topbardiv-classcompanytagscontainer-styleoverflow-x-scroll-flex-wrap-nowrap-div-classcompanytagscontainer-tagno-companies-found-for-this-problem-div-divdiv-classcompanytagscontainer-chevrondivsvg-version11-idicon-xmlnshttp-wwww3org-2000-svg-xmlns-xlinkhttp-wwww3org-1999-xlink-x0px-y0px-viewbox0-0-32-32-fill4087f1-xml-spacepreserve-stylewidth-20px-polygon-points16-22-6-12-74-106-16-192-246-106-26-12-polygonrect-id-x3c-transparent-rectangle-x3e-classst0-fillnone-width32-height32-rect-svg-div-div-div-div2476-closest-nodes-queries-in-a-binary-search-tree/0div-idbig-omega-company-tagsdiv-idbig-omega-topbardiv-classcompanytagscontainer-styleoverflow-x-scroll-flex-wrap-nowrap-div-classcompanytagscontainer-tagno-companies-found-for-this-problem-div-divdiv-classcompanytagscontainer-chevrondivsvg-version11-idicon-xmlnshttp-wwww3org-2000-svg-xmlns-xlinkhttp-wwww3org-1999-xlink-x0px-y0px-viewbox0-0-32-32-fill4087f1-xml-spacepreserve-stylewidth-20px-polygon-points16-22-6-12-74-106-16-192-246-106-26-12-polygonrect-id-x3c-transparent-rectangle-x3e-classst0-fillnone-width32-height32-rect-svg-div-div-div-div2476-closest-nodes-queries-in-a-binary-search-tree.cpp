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
    vector<int> order;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        order.push_back(root->val);
        inorder(root->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        int n=queries.size();
        vector<vector<int>> ans;
        inorder(root);
        for(int i=0;i<n;i++){
            int val=queries[i];
            auto lb=upper_bound(order.begin(),order.end(),val);
            int index=lb-order.begin();
            cout<<index<<endl;
            int lft=index<=0?-1:order[index-1];
            int rft=index==order.size()?-1:order[index];
            if(index-1>=0 and val==order[index-1]) rft=order[index-1];
            ans.push_back({lft,rft});
        }
        return ans;
    }
};