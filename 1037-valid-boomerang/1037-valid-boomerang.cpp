class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int y=points[0][1];
        int x=points[0][0];
        int y1=points[1][1];
        int x1=points[1][0];
        int y2=points[2][1];
        int x2=points[2][0];
        double m1=0,m2=0,m3=0;
        if(x==x2&&y==y2||x==x1&&y==y1||x1==x2&&y1==y2)
            return false;
        if(x1-x==0)
            m1=INT_MAX;
        else 
            m1=(double)(y1-y)/(x1-x);
        if(x2-x1==0)
            m2=INT_MAX;
        else
            m2=(double)(y2-y1)/(x2-x1);
        if(x2-x==0)
            m3=INT_MAX;
        else
            m3=(double)(y2-y)/(x2-x);
        cout<<m1<<" "<<m2<<" "<<m3<<endl;
        return m1!=m2&&m3!=m1&&m2!=m3;

    }
};