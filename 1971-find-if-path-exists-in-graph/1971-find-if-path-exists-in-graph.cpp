class Solution {
public:
    vector<int> arr[200000];
    bool b[200000];
    void dfs(int vertex){
        b[vertex]=true;
        for(auto i:arr[vertex]){
            if(b[i]) continue;
            dfs(i);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(auto i:edges){
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        dfs(source);
        return b[destination];
    }
};