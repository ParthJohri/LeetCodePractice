class Solution {
public:
    int dfs(vector<int>* adj, vector<bool>&visit, int node){
        int change=0;
        visit[node]=true;
        for(auto i:adj[node]){
            if(!visit[abs(i)]){
                change+=dfs(adj,visit,abs(i))+(i>0);
            }
        }
        return change;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> adj[n+1];
        vector<bool> visit(n+1,false);
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(-i[0]);
        }
        return dfs(adj,visit,0);
    }
};