class Solution {
public:
    void dfs(int node,vector<int>*adj,vector<bool>&visit,int target,vector<vector<int>>&ans,vector<int>temp){
        temp.push_back(node);
        if(node==target){
            ans.push_back(temp);
        }
        for(auto i:adj[node]){
            dfs(i,adj,visit,target,ans,temp);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> ans;
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                adj[i].push_back(j);
            }
        }
        vector<bool> visit(n);
        dfs(0,adj,visit,n-1,ans,vector<int>());
        return ans;
    }
};