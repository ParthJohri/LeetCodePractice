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
    unordered_map<int,int>m;
    vector<pair<int,int>> p;
    vector<int> v;
    int sum(TreeNode* root) {
        if(root==NULL) return 0;
        int leftsubtree=sum(root->left);
        int rightsubtree=sum(root->right);
        return root->val+leftsubtree+rightsubtree;
    }
    void check(TreeNode* root) {
        if(root!=NULL) 
        {
            m[sum(root)]++;
            check(root->left);
            check(root->right);
        }
    }
    static bool pairsecond(pair<int,int> p1,pair<int,int>p2)
    {
        return p1.second>p2.second;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        check(root);
        for(auto i:m) p.push_back({i.first,i.second});
        sort(p.begin(),p.end(),pairsecond);
        int mx=p[0].second;
        for(auto i:p) {
            if(i.second==mx)
                v.push_back(i.first);
        }
        return v;
    }
};