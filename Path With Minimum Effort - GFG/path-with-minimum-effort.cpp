//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define pii pair<int,pair<int,int>>

class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        dist[0][0]=0;
        priority_queue<pii,vector<pii>,greater<pii>>p;
        p.push({0,{0,0}});
        while(!p.empty()){
            auto u=p.top().second;
            int d=p.top().first;
            p.pop();
            int row=u.first;
            int col=u.second;
            int dx[4]={1,0,-1,0}; 
            int dy[4]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int x=dx[i]+row;
                int y=dy[i]+col;
                if(x>=0 and x<n and y>=0 and y<m){
                        int val=max(abs(grid[row][col]-grid[x][y]),d);
                        if(dist[x][y]>val){
                            dist[x][y]=val;
                            p.push({dist[x][y],{x,y}});
                        }
                }
            }
        }
        return dist[n-1][m-1]==INT_MAX?0:dist[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends