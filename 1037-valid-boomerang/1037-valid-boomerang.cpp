class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int y=points[0][1];
        int x=points[0][0];
        int y1=points[1][1];
        int x1=points[1][0];
        int y2=points[2][1];
        int x2=points[2][0];
        // AB!=AC
        return ((y1-y)*(x2-x)!=(y2-y)*(x1-x));

    }
};