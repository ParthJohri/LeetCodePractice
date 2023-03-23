class Solution {
public:
    bool visit[100005]={false};
    void dfs(vector<int>* adj, int node){
        visit[node]=true;
        for(auto i: adj[node]){
            if(!visit[i]){
                dfs(adj,i);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int count=0;
        vector<int> adj[n];
        for(auto i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfs(adj,i);
                count++;
            }
        }
        count-=1;
        if(n-1>connections.size()) return -1;
        return count;
    }
};