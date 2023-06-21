class Solution {
public:
    void dfs(int node,vector<int>*adj,int target,vector<vector<int>>&ans,vector<int>&temp){
        if(node==target){
            temp.push_back(node);
            ans.push_back(temp);
            temp.pop_back();
        }
        for(auto i:adj[node]){
            temp.push_back(node);
            dfs(i,adj,target,ans,temp);
            temp.pop_back();
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
        // A directed acyclic graph can never contain a self-loop.
        // No need of visit vector<bool> visit(n);
        vector<int>temp;
        dfs(0,adj,n-1,ans,temp);
        return ans;
    }
};