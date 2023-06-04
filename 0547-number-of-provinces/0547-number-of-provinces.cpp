class Solution {
public:
    void dfs(int vertex,vector<vector<int>> &adj,vector<bool> &b){
        b[vertex]=true;
        for(int i=0;i<adj[vertex].size();i++){
            if(b[i]) continue;
            if(adj[vertex][i]==1)
            dfs(i,adj,b);
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces=0;
        vector<bool> b(isConnected.size(),false);
        for(int i=0;i<isConnected.size();i++){
            if(b[i]) continue;
            ++provinces;
            dfs(i,isConnected,b);
        }
        return provinces;
    }
};