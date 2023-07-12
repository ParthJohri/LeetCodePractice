class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<int> adj[n],outdegree(n,0);
        queue<int>q;
        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                adj[j].push_back(i);
                outdegree[i]++;
            }
        }
        for(int i=0;i<n;i++){
            if(outdegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int curr=q.front();
                q.pop();
                ans.push_back(curr); 
                for(auto i:adj[curr]){
                    outdegree[i]--;
                    if(outdegree[i]==0){
                        q.push(i);
                    }
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};