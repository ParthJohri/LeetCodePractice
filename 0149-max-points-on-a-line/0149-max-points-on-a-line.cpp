class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=INT_MIN;
        double slope;
        if(points.size()==1) return 1;
        for(int i=0;i<points.size();i++){
            map<double,int> m;
            for(int j=i+1;j<points.size();j++){
                if(abs(points[i][0]-points[j][0])!=0)
                slope=1.0*((points[i][1]-points[j][1]))/((points[i][0]-points[j][0]));
                else
                slope=INT_MAX;
                m[slope]++;
                ans=max(ans,m[slope]+1);
            }
        }
        return ans;
    }
};