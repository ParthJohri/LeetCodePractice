class Solution {
public:
    bool recur(vector<int>*adj,int node,int par,vector<int>&p){
        bool tag=true;
        for(auto i:adj[node]){
            if(p[i]==-1){
                p[i]=node;
                tag = tag and recur(adj,i,node,p);
            }
            else tag=false;
        }
        return tag;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> adj[n];
        vector<vector<int>> p(n);
        int count=0;
        
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1) {
                adj[i].push_back(leftChild[i]);
                p[leftChild[i]].push_back(i);
            }
            if(rightChild[i]!=-1) {
                adj[i].push_back(rightChild[i]);  
                p[rightChild[i]].push_back(i);
            }
        }
        
        for(int i=0;i<=n-1;i++){
            if(p[i].size()==0) ++count;
            else if(p[i].size()>1) return false;
        }
        vector<int>par(n,-1);
        bool check = recur(adj,0,-1,par);
        return count==1 and check;
    }
};