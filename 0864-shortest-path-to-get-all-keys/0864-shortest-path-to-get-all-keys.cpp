#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int startrow, startcol, n = grid.size(), c = grid[0].size(), keys = 0, count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '@') {
                    startrow = i;
                    startcol = j;
                }
                else if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    keys++;
                }
            }
        }
        int targetKeys = (1 << keys) - 1;
        // suppose we have 3 keys, therefore 
        // targetKeys value comes out to be 111 - 7 
        // which means abc all 3 keys are present
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        int rc = startrow * c + startcol;
        map<pair<int, int>, set<int>> m;
        queue<pair<int, int>> q;
        q.push({rc, 0});
        m[{rc, 0}].insert(0);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto curr = q.front();
                q.pop();
                int cx = curr.first / c;
                int cy = curr.first % c;
                int currKeys = curr.second;
                if (currKeys == targetKeys)
                    return count;
                for (int i = 0; i < 4; i++) {
                    int x = dx[i] + cx;
                    int y = dy[i] + cy;
                    if (x < 0 || y < 0 || x >= n || y >= c)
                        continue;
                    char cell = grid[x][y];
                    if (cell == '#')
                        continue;
                    int nextKeys = currKeys;
                    if (cell >= 'a' && cell <= 'z') {
                        int keyBit = 1 << (cell - 'a');
                        nextKeys |= keyBit;
                    }
                    if (cell >= 'A' && cell <= 'Z') {
                        int lockBit = 1 << (cell - 'A');
                        if ((currKeys & lockBit) == 0)
                            continue;
                    }
                    int nrc = x * c + y;
                    if (m[{nrc, nextKeys}].count(nextKeys) == 0) {
                        q.push({nrc, nextKeys});
                        m[{nrc, nextKeys}].insert(nextKeys);
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
