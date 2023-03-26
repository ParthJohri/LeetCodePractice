class Solution {
public:
   int ans=-1;
   void dfs(int node,vector<int>&edges,vector<bool>&visit,vector<int>&store){
        if(node==-1) return;
        if(visit[node]) {
            int count=-1;
            for(int i=0;i<store.size();i++){
                if(store[i]==node) {
                    count=i;
                    break;
                }
            }
            if(count==-1) return;
            int l=store.size()-count;
            ans=max(ans,l);
            return;
        }
        visit[node]=true;
        store.push_back(node);
        dfs(edges[node],edges,visit,store);
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<bool> visit(n+1,false);
        for(int i=0;i<n;i++){
            if(visit[i]) continue;
            vector<int>store;
            dfs(i,edges,visit,store);
        }
        return ans;
    }
};