class Solution {
public:
    bool visit[1000004]={false};
    void dfs(int s,int e,vector<pair<int,int>>*adj,int& val){
        visit[s]=true;
        for(auto i:adj[s]){
            val=min(val,i.second);
            if(!visit[i.first])
                dfs(i.first,e,adj,val);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[1000004];
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        int start=1,end=n,ans=INT_MAX;
        dfs(start,n,adj,ans);
        return ans;
    }
};