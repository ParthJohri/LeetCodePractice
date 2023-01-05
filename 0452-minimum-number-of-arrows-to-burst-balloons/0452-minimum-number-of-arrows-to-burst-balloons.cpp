class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=1;
        if(points.size()<=1) return points.size();
        sort(points.begin(),points.end());
        int i=0,j=1,c=points[0][1];
        while(j<points.size()){
            if(c<points[j][0]){
                ++ans;
                c=points[j][1];
            }
            else
                c=min(c,points[j][1]);
            j++;
        }
        return ans;
    }
};