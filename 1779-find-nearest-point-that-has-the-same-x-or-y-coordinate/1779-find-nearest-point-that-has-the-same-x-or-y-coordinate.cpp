class Solution {
public:
    typedef pair<int,int> pi;
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        priority_queue<pi,vector<pi>,greater<pi>> p;
        for(int i=0;i<points.size();i++)
        {
            if(x==points[i][0]||y==points[i][1])
            {
                int d=abs(x-points[i][0])+abs(y-points[i][1]);
                p.push({d,i});
            }
        }
        if(p.empty()) return -1;
        return p.top().second;
    }
};