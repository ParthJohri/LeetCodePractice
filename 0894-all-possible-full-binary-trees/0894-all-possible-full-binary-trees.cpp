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
    map<int,vector<TreeNode*>> dp;
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if(n%2==0) return {};
        if(dp.find(n)!=dp.end()) return dp[n];
        else if(n==1){
            TreeNode* node=new TreeNode(0);
            ans.push_back(node);
            return ans;
        }
        for(int i=1;i<=n-1;i+=2){
            auto left = allPossibleFBT(i);
            auto right = allPossibleFBT(n-1-i);
            for(auto i:left){
                for(auto j:right){
                    TreeNode* node=new TreeNode(0);
                    node->left=i;
                    node->right=j;
                    ans.push_back(node);
                }
            }
        }
        return dp[n]=ans;
    }
};