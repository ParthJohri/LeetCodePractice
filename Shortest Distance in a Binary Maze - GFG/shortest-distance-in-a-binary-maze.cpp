//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define pii pair<int,pair<int,int>>
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[source.first][source.second]=0;
        priority_queue<pii,vector<pii>,greater<pii>>p;
        p.push({dist[source.first][source.second],{source.first,source.second}});
        while(!p.empty()){
            auto u=p.top().second;
            int d=p.top().first;
            p.pop();
            int dx[4]={1,0,-1,0};
            int dy[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int x=dx[i]+u.first;
                int y=dy[i]+u.second;
                if(x>=0 and x<n and y>=0 and y<m and grid[x][y]==1 and dist[x][y]>d+1){
                        dist[x][y]=d+1;
                        p.push({dist[x][y],{x,y}});
                }
            }
        }
        if(dist[destination.first][destination.second]==INT_MAX) return -1;
        else return dist[destination.first][destination.second];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends