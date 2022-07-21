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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return binarySearchAlgo(0,nums.size()-1,nums);
    }
    TreeNode* binarySearchAlgo(int l,int h,vector<int> &nums){
        if(l>h) return NULL;
        int mid=l+(h-l)/2;
        TreeNode* temp=new TreeNode(nums[mid]);
        temp->left=binarySearchAlgo(l,mid-1,nums);
        temp->right=binarySearchAlgo(mid+1,h,nums);
        return temp;
    }
};