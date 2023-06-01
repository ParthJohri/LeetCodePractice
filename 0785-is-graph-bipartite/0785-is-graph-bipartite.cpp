class Solution {
public:
    bool bfs(vector<int> *adj,int start,vector<int>&color){
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int p=q.front();
                q.pop();
                for(auto node:adj[p]){
                    if(color[node]==-1){
                        color[node]=!color[p];
                        q.push(node);
                    }
                    if(color[node]==color[p]) return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            for(auto j:graph[i])
            adj[i].push_back(j);
        }
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                bool flag=bfs(adj,i,color);
                if(flag==false) return false;
            }
        }
        return true;
    }
};