class Solution {
public:
    typedef pair<double,vector<int>> pi;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi,vector<pi>,greater<pi>> p;
        for(auto i:points)
        {
            int x=i[0];
            int y=i[1];
            double v=sqrt(pow(x,2)+pow(y,2));
            p.push({v,i});
        }
        vector<vector<int>> v;
        while(k--)
        {
            v.push_back(p.top().second);
            p.pop();
        }
        return v;
    }
};