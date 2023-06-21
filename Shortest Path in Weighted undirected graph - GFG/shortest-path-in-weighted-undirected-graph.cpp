//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<int> path(n+1,-1);
        for(int i=1;i<=n;i++) path[i]=i;
        vector<vector<int>> adj[n+1];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        p.push({0,1});
        vector<int> dist(n+1,INT_MAX);
        dist[1]=0;
        while(!p.empty()){
            int n=p.top().second,d=p.top().first;
            p.pop();
            for(auto node:adj[n]){
                int node_no=node[0];
                int w=node[1];
                if(dist[node_no]>dist[n]+w){
                    dist[node_no]=dist[n]+w;
                    path[node_no]=n;
                    p.push({dist[node_no],node_no});
                }
            }
        }
        if(dist[n]==INT_MAX) return {-1};
        vector<int> ans;
        while(path[n]!=n){
            ans.push_back(n);
            n=path[n];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends