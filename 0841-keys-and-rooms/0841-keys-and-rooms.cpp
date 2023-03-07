class Solution {
public:
    void dfs(int node,vector<int>*adj,bool* visit){
        visit[node]=true;
        for(auto i:adj[node]){
            if(!visit[i]){
                dfs(i,adj,visit);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> adj[100005];
        for(int i=0;i<rooms.size();i++){
            for(auto j:rooms[i]){
                adj[i].push_back(j);   
            }
        }
        bool visit[rooms.size()+1];
        memset(visit,false,sizeof visit);
        dfs(0,adj,visit);
        for(int i=0;i<rooms.size();i++){
            if(visit[i]==false) {cout<<i<<endl;return false;}
        }
        return true;  
    }
};