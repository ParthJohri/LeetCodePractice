class Solution {
public:
    int dfsansvalue=0;
    
    int dfs (int node,vector<int>*adj,vector<int>& t){
        int time=0;
        for(auto n:adj[node]){
            time=t[node]+dfs(n,adj,t);
        }
        dfsansvalue=max(dfsansvalue,time);
        return time;
    }
    int numOfMinutes(int n, int h, vector<int>& manager, vector<int>& time) {
        vector<int> adj[manager.size()+1];
        for(int i=0;i<manager.size();i++){
            if(i!=h)
            adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        q.push({h,0});
        int ans=time[h];
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                int timetaken=node.second+time[node.first];
                for(auto n:adj[node.first]){
                    q.push({n,timetaken});
                }
                ans=max(ans,timetaken);
            }
        }
        // dfs(h,adj,time);
        return ans;
    }
};