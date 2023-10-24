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
    TreeNode* sr=new TreeNode(0);
    TreeNode* dr=new TreeNode(0);
    
    void search(TreeNode* root,int sv,int dv){
        if(root==NULL) return;
        if(root->val==sv) sr=root;
        if(root->val==dv) dr=root;
        search(root->left,sv,dv);
        search(root->right,sv,dv);
    }
    
    TreeNode* lca(TreeNode* root,TreeNode* s,TreeNode* d){
        if(root==NULL or s==root or d==root) return root;
        TreeNode* l=lca(root->left,s,d);
        TreeNode* r=lca(root->right,s,d);
        if(l==NULL) return r;
        if(r==NULL) return l;
        return root;
    }
    
    void rightPath(TreeNode* dr, TreeNode* lc,string& st,string& ans){
        if(lc==NULL) return ;
        if(dr==lc) {
            ans=st;
            return;
        }
        st.push_back('L');
        rightPath(dr,lc->left,st,ans);
        st.pop_back();
        st.push_back('R');
        rightPath(dr,lc->right,st,ans);
        st.pop_back();
    }
    
    int dist(TreeNode* sr,TreeNode* lc){
        if(lc==NULL) return 1e9;
        if(lc==sr) return 0;
        return 1+min(dist(sr,lc->left),dist(sr,lc->right));
    }
    
    string getDirections(TreeNode* root, int s, int d) {

        search(root,s,d);
        TreeNode* lc=lca(root,sr,dr);
        string ans="";
        
        int count = dist(sr,lc);
        string str="";
        
        for(int i=1;i<=count;i++) str+="U";
        
        string temp="";
        rightPath(dr,lc,temp,ans);
        ans=str+ans;
        
        return ans;
    }
};