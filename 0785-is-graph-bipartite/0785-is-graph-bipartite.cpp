class Solution {
public:
    bool dfs(vector<vector<int>>&G, vector<int>& colors, int i, int color) {
        colors[i] = color;
        for (int j = 0; j < G[i].size(); j++) {
            int k = G[i][j]; // adjacent node
            if (colors[k] == -color) continue;
            if (colors[k] == color || !dfs(G, colors, k, -color)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& G) {
        int n = G.size();
        vector<int> colors(n,false);
        for (int i = 0; i < n; i++) {
            if (colors[i] == 0 && !dfs(G, colors, i, 1)) 
                return false;            
        }
        return true;
    }
};