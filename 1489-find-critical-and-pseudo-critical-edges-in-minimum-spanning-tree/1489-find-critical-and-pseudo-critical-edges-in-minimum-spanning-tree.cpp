class Solution
{
    public:
        int minimax(vector<pair<int, int>> *v, int n, int src, int dst)
        {
            vector<int> dist(n, INT_MAX);
            priority_queue<pair<int, int>> p;
            p.push({ dist[src] = 0,
                src });
            while (!p.empty())
            {
                auto[weight, node] = p.top();
                p.pop();
                if(-weight>dist[node]) continue;
                for (auto[adj, w]: v[node])
                {
                    if (adj == dst and node == src) continue;
                    if (dist[adj] > max(dist[node], w))
                    {
                        dist[adj] = max(dist[node], w);
                        p.push({-dist[adj],
                            adj });
                    }
                }
            }
            return dist[dst];
        }
    vector<vector < int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector < int>> &edges)
    {
        vector<pair<int, int>> v[n];
        vector<vector < int>> ans(2);
        for (auto i: edges)
        {
            v[i[0]].push_back({ i[1],
                i[2] });
            v[i[1]].push_back({ i[0],
                i[2] });
        }
        for (int i = 0; i < edges.size(); i++)
        {
                auto e=edges[i];
                int u = e[0], d= e[1],w=e[2];
                int m=minimax(v,n,u,d);
                if (w < m)
                {
                    ans[0].push_back(i);
                }
                else if (w == m)
                {
                    ans[1].push_back(i);
                }
        }
        return ans;
    }
};