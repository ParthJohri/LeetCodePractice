class Solution {
public:
    void bfs(vector<int>& dist, int& node, vector<bool>& visit, vector<int> *adj){
        queue<int> q;
        q.push(node);
        dist[node]=0;
        int step=0;
        visit[node]=true;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int val=q.front();
                q.pop();
                dist[val]=step;
                for(auto i:adj[val]){
                    if(visit[i]) continue;
                    visit[i]=true;
                    q.push(i);
                }
                step++;
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(edges[i]==-1) continue;
            adj[i].push_back(edges[i]);
        }
        vector<bool> visit(n,false),visit2(n,false);
        vector<int> d1(n,INT_MAX),d2(n,INT_MAX);
        bfs(d1,node1,visit,adj);
        bfs(d2,node2,visit2,adj);
        int a1=INT_MAX,a2=-1;
        for(int i=0;i<n;i++){
            if(d1[i]==INT_MAX or d2[i]==INT_MAX) continue;
            if(a1>max(d1[i],d2[i])){
                a1=max(d1[i],d2[i]);
                a2=i;
            }
        }
        return a2;
    }
};